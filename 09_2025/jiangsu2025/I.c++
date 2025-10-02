using namespace std;
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <sstream>
#include <tuple>
#include <bitset>
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
    ifstream cin("I.in");
    int n;
    cin >> n;
    vi fa(1e6, 0), ba(1e6, 0), ta(1e6, 0);
    unordered_map<ll,int> fb, ft, bt;

    vector<tuple<int,int,int> > names(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        fa[a]++;
        ba[b]++;
        ta[c]++;
        tuple<int,int,int> tp = make_tuple(a,b,c);
        names[i] = tp;
        ll fbh = (a << 21) + b;
        ll fth = (a << 21) + c;
        ll bth = (b << 21) + c;
        fb[fbh]++;
        ft[fth]++;
        bt[bth]++;
    }
    ll maxc = 0;
    for (int i = 0; i < n; i++) {
        int f= get<0>(names[i]), b = get<1>(names[i]), t = get<2>(names[i]);
        // maxc += fa[f] * ba[b] * ta[t];
        // pairwise overlaps
        // cout << fa[f] -1 << " " << ba[b] - 1<< " " << ta[t] -1 <<endl;
        ll fbh = (f << 21) + b;
        ll fth = (f << 21) + t;
        ll bth = (b << 21) + t;
        // take first
        maxc += (ba[b]-1) * (ta[t]-1) - bt[bth] + 1;
        cout << (ba[b]-1) * (ta[t]-1) - bt[bth] + 1 << " ";
        // take mid
        maxc += (fa[f]-1) * (ta[t]-1) - ft[fth] + 1;
        cout << (fa[f]-1) * (ta[t]-1) - ft[fth] + 1 << " ";
        // take last
        maxc += (fa[f]-1) * (ba[b]-1) - fb[fbh] + 1;
        cout << (fa[f]-1) * (ba[b]-1) - fb[fbh] + 1 << " ";
        cout << endl;
        // maxc -= fb[fbh];
        // maxc -= bt[bth];
        // maxc -= ft[fth];
        // cout << "up " << fa[f] * ba[b] * ta[t] << " fbc " <<  fb[fbh] << " ftc " <<  ft[fth] << " btc " <<  bt[bth] << endl;
    }
    cout << maxc << endl;
    return 0;
}