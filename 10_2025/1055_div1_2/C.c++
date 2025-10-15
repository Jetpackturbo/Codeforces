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
typedef vector<vector<ll> > vvll;
typedef vector<string> vs;

// #define endl '\n'
// #define no cout<<"NO"<<endl
// #define yes cout<<"YES"<<endl
#define en end()
#define be begin()
#define fo(a,b,c) for(int i = a; i < b; i+=c)
#define srt(a) sort(a.be, a.en)
#define NMAX numeric_limits<ll>::max()
const ll MOD = 998244353, mod=1e9+7;
#define NMIN numeric_limits<int>::min()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (int &c : v) cout << c << " "


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("B.in");
    int T;
    cin >> T;
    while (T--) {
        int n, Q;
        cin >> n >> Q;
        vi zeroc(n, 0), onec(n, 0);
        queue<int> zq, oq;
        int cs; cin >> cs;
        if (cs == 0)
            zeroc[0]++;
            zq.push(0);
        else {
            onec[0]++;
            oq.push(0);
        }
        fo(1,n,1) {
            int c; cin >> c;
            if (c == 0)
                zeroc[i]++;
                zq.push(0);
            else {
                onec[i]++;
                oq.push(0);
            }
            zeroc[i] += zeroc[i-1];
            onec[i] += onec[i-1];
        }
        vi ocp0, ocp1, ocp2;
        vi zcp0, zcp1, zcp2;
        int op0 = 0, op1 = 1, op2 = 2;
        while (!oq.empty()) {
            int c = oq.front();
            oq.pop();
            
        }
        while (Q--) {
            int l, r;
            cin >> l >> r;
            if (r - l + 1 % 3 != 0) {
                cout << -1 << endl;
                continue;
            }
            else if (zeroc[r - 1] - zeroc[l-1] % 3 != 0 || onec[r - 1] - onec[l-1] % 3) {
                cout << -1 << endl;
                continue;
            }
            // must be possible
        }
    }
    return 0;
}