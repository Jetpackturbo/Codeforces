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
#define no cout<<"no"<<endl
#define yes cout<<"yes"<<endl
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
    // ifstream cin("K.in");
    int n, a, b;
    cin >> n >> a >> b;
    if (a == 1 && b == 1) {
        no;
        return 0;
    }
    if (a + b > n + 1) {
        no;
        return 0;
    }
    yes;
    vi ret(n, 0);
    if (b == 1) {
        ret[n-1] = n;
        for (int i = 0; i < a - 1; i++) {
            ret[i] = n - a + i + 1;
        }
        for (int i = a-1; i < n - 1; i++) {
            ret[i] = i - a + 2;
            // cout << i << " " << ret[i] << endl;
        }
        cout_space(ret);
        return 0;
    }
    for (int i = 0; i < a; i++) {
        ret[i] = n - a + i + 1;
        // cout << i << " " << ret[i] << endl;
    }
    if (a + b == n + 1) {
        for (int i = 0; i < b - 1; i++) {
            ret[n- i - 1] = i + 1;
        }
        cout_space(ret);
        return 0;
    }
    
    int ci = n - a;
    for (int i = 0; i < b - 1; i++) {
        ret[n- i - 1] = ci - b + i + 2;
        // cout << n - i -1 << " " << ret[n - i - 1] << endl;
    }
    ci -= b;
    ci++;
    for (int i = a; i < n - b + 1; i++) {
        ret[i] = ci;
        // cout << i << " " << ret[i] << endl;
        ci--;
    }
    cout_space(ret);
    return 0;
}