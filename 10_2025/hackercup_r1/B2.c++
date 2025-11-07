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

#define endl '\n'
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define en end()
#define be begin()
#define fo(a,b,c) for(int i = a; i < b; i+=c)
#define srt(a) sort(a.be, a.en)
#define NMAX numeric_limits<ll>::max()
#define nmax numeric_limits<int>::max()
const ll MOD = 998244353, mod=1e9+7;
#define NMIN numeric_limits<int>::min()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (int &c : v) cout << c << " "

vector<long long> trial_division(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

ll choose(ll a, ll b) {
    ll total = a;
    for (int i = 1; i < b; i++) {
        total *= a - i;
        total /= i;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("B2.in");
    // ofstream cout("B2.out");
    int T;
    cin >> T;
    for (int testc = 1; testc <= T; testc++) {
        ll n, a, b;
        cin >> n >> a >> b;
        vll div = trial_division(b);
        // factors come back sorted
        ll count = 0;
        unordered_map<ll, int> divc;
        for (ll &c : div) {
            divc[c]++;
        }
        ll tc = 1;
        for (auto &cp : divc) {
            tc *= cp.second + 1;
            tc %= mod;
        }
        count += choose(max(2*n, (ll)div.size()), min(2*n,(ll)div.size()));
        // now we just need to exclude those less than a
        if (a < b) {
            // otherwise we can just say this good

        }
        cout << "Case #" << testc << ":" << (count + mod) % mod << endl;
    }
    return 0;
}