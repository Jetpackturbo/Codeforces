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
    int x, y;
    cin >> x >> y;
    double qc = M_PI * 5;
    vvi isc(x, vi(y, 0));
    for (int i = 0; i < x; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < y; j++) {
            if (s[j] == 'O')
                isc[i][j] = 1;
        }
    }
    vector<vector<double>> dp(2*x, vector<double>(2*y, numeric_limits<double>::max()/10));
    dp[0][0] = 0;
    for (int i = 1; i < 2*x; i++) {
        dp[i][0] = dp[i-1][0] + 5;
    }
    for (int i = 1; i < 2*y; i++) {
        dp[0][i] = dp[0][i-1] + 5;
    }
    for (int i = 1; i < 2 * x; i++) {
        for (int j = 1; j < 2 * y; j++) {
            if (i == j && i % 2 == 1) {
                continue;
            }
            if (isc[i / 2][j / 2] == 1) {
                if ()
                    // currently on right edge of circle
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + qc);
                else{
                    continue;
                }
            }
            else {
                // square, do a linear add
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 5;
            }
        }
    }
    cout << dp[2*x-1][2*y-1] << endl;
    return 0;
}