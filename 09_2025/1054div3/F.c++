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
typedef uint32_t i128;
#define endl '\n'
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define en end()
#define be begin()
#define fo(a,b,c) for(int i = a; i < b; i+=c)
#define srt(a) sort(a.be, a.en)
#define NMAX numeric_limits<ll>::max()
const ll MOD = 998244353, mod=1e9+7;
#define NMIN numeric_limits<int>::min()

#define cout_space(v) for (auto &c : v) cout << c << " "


ll min_turns(ll h, ll d) {
    ll lo = 0, hi = d, ansR = d;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll s = min(d, mid + 1);
        ll q = d / s;
        ll r = d % s;
        // compute minimal movement cost for this s
        i128 cost = (i128)r * (q + 1) * (q + 2) / 2 + (i128)(s - r) * q * (q + 1) / 2;
        // require cost <= h + R - 1
        i128 rhs = (i128)h + mid - 1; 
        if (cost <= rhs) {
            ansR = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return d + ansR;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll h, d;
        cin >> h >> d;
        cout << min_turns(h, d) << endl;
    }
    return 0;
}