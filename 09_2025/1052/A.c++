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
        cin >> n;
        unordered_map<int, int> nums;
        int bl = 0;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            nums[c]++;
        }
        for (int i = 1; i <= 100; i++) {
            int ct = 0;
            for (auto &cp : nums) {
                if (cp.second >= i) {
                    ct++;
                }
            }
            bl = max(i*ct, bl);
        }
        cout << bl << endl;
    }
    return 0;
}