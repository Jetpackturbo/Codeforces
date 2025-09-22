using namespace std;
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <sstream>
#include <bitset>
#include <tuple>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <iostream>
#include <set>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
typedef vector<vector<int > > vvi;
typedef vector<vector<vector<int > > > vvvi;
typedef vector<vector<vector<ll > > > vvvll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pair<int, int > > vpi;
typedef vector<tuple<int, int > > vti;
typedef vector<vector<tuple<int, int > > > vvti;
typedef vector<tuple<ll, ll> > vtll;
typedef vector<bool> vb;
typedef vector<vector<long long> > vvll;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;

#define NMAX numeric_limits<ll>::max()

const int MOD = 998244353;

int main(){
    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi opos;
        // opos.push_back(-2);
        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                opos.push_back(i);
        if (opos.size() == 0) {
            cout << "YES" << endl;
            continue;
        }
        // opos.push_back(n+1);
        // bool works = true;
        // for(int i = 1; i < opos.size()-1; i++) {
        //     if (opos[i] -opos[i-1] > 2 && opos[i+1] - opos[i] > 2) {
        //         works = false;
        //         break;
        //     }
        // }
        vvb dp(opos.size()+1, vb(2,false));
        // 1 for looking r, 0 for none
        dp[0][0] = true;
        if(opos[0] == 0) {
            dp[1][0] = true;
        }
        dp[1][1] = true;
        for (int i = 1; i < opos.size(); i++) {
            if (i == opos.size()- 1 && opos[i] == n-1) {
                dp[i+1][0] = dp[i][0] || ((opos[i] - opos[i-1] <= 2) ? dp[i][1]: false);
                
                continue;
            }
            if (opos[i] - opos[i-1] == 2) {
                dp[i+1][0] = dp[i][1];
                dp[i+1][1] = dp[i][0];
            }
            else if (opos[i] - opos[i-1] == 1) {
                dp[i+1][0] = dp[i][1] || dp[i][0];
                dp[i+1][1] = dp[i][0] || dp[i][1];
            }
            else {
                dp[i+1][1] = dp[i][0];
            }
        }        
        if (dp[dp.size()-1][0])
            cout << "YES" << endl;
        else if (opos.size() == 1 && opos[0] == n-1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        // if (works)
        //     cout << "YES" << endl;
        // else
        //     cout << "NO" << endl;
    }
    return 0;
}