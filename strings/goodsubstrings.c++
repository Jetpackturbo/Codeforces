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
    // ifstream cin("c.in");
    string s, p;
    cin >> s >> p;
    int ck, n = s.length();
    cin >> ck;
    vi good(26,0);
    fo(0,26,1)
        good[i] = p[i] - '0';
    vll badn(n+1, 0);
    for (int i = 1; i <= n; i++) {
        badn[i] = badn[i-1] + 1 - good[s[i-1] - 'a'];
    }
    ll count = 0;
    
    vll pows(n);
    pows[0] = 1;
    for (int i = 1; i < n; i++)
        pows[i] = (pows[i-1] * 26) % mod;

    vll h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * pows[i]) % mod;

    for (int l = 1; l <= n; l++) {
        unordered_set<ll> hs;
        for (int i = 0; i <= n - l; i++) {
            if (badn[i + l] - badn[i] > ck)
                continue;
            ll cur_h = (h[i + l] + mod - h[i]) % mod;
            cur_h = (cur_h * pows[n-i-1]) % mod;
            hs.insert(cur_h);
        }
        // cout << hs.size() << endl;
        count += hs.size();
    }
    cout << count << endl;
    return 0;
}