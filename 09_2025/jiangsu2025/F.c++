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
#define cout_space(v) for (auto &c : v) cout << c << " "


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("F.in");
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        vi opc(n,0), comp(n,0), bpt(n,numeric_limits<int>::max()/5);
        int s;
        cin >> s;
        int opt = 0, ops = 0;
        for (int i = 0; i < s; i++) {
            int ct;
            cin >> ct;
            char p;
            cin >> p;
            int pi = p - 'A';
            string res;
            cin >> res;
            if (comp[pi])
                continue;
            if (res == "ac") {
                opt += opc[pi] * 20 + ct;
                ops++;
                comp[pi] = true;
            }
            else if (res == "rj") {
                opc[pi]++;
            }
            else if (res == "pd" && bpt[pi] == numeric_limits<int>::max()/5) {
                // account for prev offset
                bpt[pi] = ct + 20 * opc[pi];
            }
        }
        if (ops > a || (ops == a && opt < b)) {
            cout << 0 << endl;
            continue;
        }
        srt(bpt);
        bool works = false;
        for (int i = 0; i < n; i++ ){
            if (bpt[i] == numeric_limits<int>::max()/5) {
                break;
            }
            opt += bpt[i];
            ops++;
            if (ops > a) {
                cout << i+1 << endl;
                works = true;
                break;
            }
            else if (ops == a && opt < b) {
                cout << i+1 << endl;
                works = true;
                break;
            }
        }
        if (!works)  
            cout << -1 << endl;
    }
    return 0;
}