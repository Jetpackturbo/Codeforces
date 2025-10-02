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
    ifstream cin("K.in");
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.length();
        ll res = 0;
        
        // do palindrome calculation (longest palindrome ending)
        // using z-function
        string r = s;
        reverse(r.begin(), r.end());
        string t = r + "#" + s;

        vector<int> Z = z_function(t);  // standard O(n)

        vector<int> ans(n);
        int offset = n + 1;

        for (int i = 0; i < n; i++) { // prefix length i+1
            int L = i+1;
            int best = 1; // at least 1 char suffix is palindrome
            for (int j = offset; j <= offset + i; j++) {
                if (j + Z[j] == offset + L) {
                    best = max(best, Z[j]);
                }
            }
            ans[i] = best;
        }

        // otherwise would loop back around more than once
        // now we just want to see if there is a better option with longer reversing
        cout << res << endl;
    }
    return 0;
}