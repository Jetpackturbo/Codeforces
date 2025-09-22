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
        int n, m;
        cin >> n >> m;
        vector<int> used(m+1,0);
        // bitset<100001> used;
        vector<vector<int > > seen(m+1);
        vector<vector<int> > assigned(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int a;
                cin >> a;
                if (seen[a].size() <= 1) {
                    seen[a].push_back(i);
                }
                used[a] = 1;
                assigned[i].push_back(a);    
            }    
        }
        int fc = 0;
        for (int &c : used) {
            fc += c;
        }
        if (fc != m) {
            cout << "NO" << endl;
            continue;
        }
        int mandatory = 0;
        vector<int> nused(m+1, 0);
        // extract all mandatory sets
        for (int i = 1; i <= m; i++) {
            if (seen[i].size() == 1) {
                for (int &c :assigned[seen[i][0]]) {
                    nused[c] = 1;
                }
                mandatory++;
            }
        }
        int cc = 0;
        for (int &c : nused) {
            cc += c;
        }
        // cout << cc << endl;
        if (cc == m && n - mandatory < 2) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}