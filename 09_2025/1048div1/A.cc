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
const ll MOD = 998244353, mod=1e9+7;
#define NMIN numeric_limits<int>::min()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (int &c : v) cout << c << " "
#define rvrs(v) reverse(v.be, v.en)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("A.in");
    int T;
    cin >> T;
    while (T--) {
        ll x, k;
        cin >> k >> x;
        // only need to choose for x < 2^k
        ll cc = x, cv = (1 << (k+1)) - x;
        vi ret;
        ll ev = 1 << k;
        while (cc != ev) {
            if (cc < ev) {
                cv -= cc;
                cc *= 2;
                ret.push_back(1);
                cout << "1 " << cc << " " << cv << endl;
            }
            else {
                cc -= cv;
                cv *= 2;
                ret.push_back(2);
                cout << "2 " << cc << " " << cv << endl;
            }
        }
        rvrs(ret);
        cout << ret.size() << endl;
        cout_space(ret);
        cout << endl;
    }
    return 0;
}