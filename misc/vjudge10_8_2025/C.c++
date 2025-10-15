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
    // ifstream cin("C.in");
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi bosses(n);
        intin(bosses, n);
        vvi dp(n+1, vi(2,numeric_limits<int>::max()/10));
        dp[0][0] = 0;
        dp[1][1] = bosses[0] == 1 ? 1 : 0;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-2][1]);
            if (bosses[i-1] == 1) {
                dp[i][1] = min(1 + dp[i-1][0], 1 + dp[i-2][0] + (bosses[i-2] == 1 ? 1 : 0));
            }
            else {
                dp[i][1] = min(dp[i-1][0], dp[i-2][0] + (bosses[i-2] == 1 ? 1 : 0));
            }
            // cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        cout << min(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}