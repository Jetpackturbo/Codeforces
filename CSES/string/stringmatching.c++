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
    // ifstream cin("stringmatching.in");
    // using rabin-karp
    string s, p;
    cin >> s >> p;
    int n = s.length(), m = p.length();
    if (m > n) {
        cout << 0 << endl;
        return 0;
    }
    else if (m == n) {
        cout << (s == p ? 1 : 0) << endl;
        return 0;
    }
    vll pows(n, 1);
    for (int i = 1; i < n; i++) {
        pows[i] = (pows[i-1] * 31) % mod;
    }
    vll shash(n+1,0);
    for (int i = 1; i <= n; i++) {
        shash[i] = (shash[i-1]+ (s[i-1] - 'a' + 1)*pows[i-1]) % mod;
    }
    ll phash = 0;
    for (int i = 0; i < m; i++) {
        phash += (p[i] - 'a' + 1)*pows[i];
        phash %= mod;
    }
    // cout << phash << endl;
    int count = 0;
    for (int i = 0; i <= n - m + 1; i++) {
        // cout << shash[i + m] - shash[i] << endl;
        if ((shash[i + m] - shash[i] + mod) % mod == (pows[i]*phash)%mod)
            count++;
    }
    cout << count << endl;
    return 0;
}