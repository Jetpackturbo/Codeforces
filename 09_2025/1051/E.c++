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

#define NMAX numeric_limits<ll>::max()

const int MOD = 998244353;

int main(){
    // ifstream cin("E.in");
    int T;
    cin >> T;
    while(T--){
        int n;
        string s;
        cin >> n >> s;
        bool works = true;
        string rs = "";
        int cs = 0;
        // int lc = 0;
        for (int i = 0; i < n; i++) {
            cs += s[i] == '(' ? 1 : -1;
            // lc += s[i] == '(' ? 1 : 0;
            if (cs < 0) {
                //here we note that s[i] must also be a ')'
                if (i == n-1) {
                    works = false;
                    continue;
                }
                if (s[i+1] == ')') {
                    cs += 3;
                    // swap for a '(('
                    rs += "((";
                    i++;
                }
                else {
                    works = false;
                    break;
                }
            }
            else {
                rs += s[i];
            }
        }
        if (!works) {
            cout << -1 << endl;
        }
        else {
            if (cs % 4 != 0) {
                cout << -1 << endl;
                //unfixable
                continue;
            }
            if (cs == 0)
                cout << rs << endl;
            else {
                // here we just do a linear parse and see if we can adjust down
                // note we must take the total down by cs;
                works = false;
                int ncs = 0;
                for (int i = n-1 ; i >= 0; i--) {
                    ncs += s[i] == '(' ? 1 : -1;
                    if (s[i] == '(' && s[i-1] == '(') {
                        cs -= 2;
                        rs[i] = ')';
                        rs[i-1] = ')';
                        ncs -= 2;
                    }
                    if (ncs > 0) {
                        break;
                    }
                    if (cs == 0) {
                        works = true;
                        break;
                    }
                }
                if (works) {
                    cout << rs << endl;    
                }
                else {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}