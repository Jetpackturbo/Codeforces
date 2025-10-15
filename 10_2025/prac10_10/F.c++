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
    // ifstream cin("F.in");
    ll l, r;
    cin >> l >> r;
    // string line;
    // getline(cin, line); 
    // stringstream chars(line);
    vi nums(r-l+1, 0);
    ll ff = 1e6-1, fb = 1e6, ffb = 1e6;
    ll ffdist = NMAX/10, fbdist = NMAX/10, ffbdist = NMAX/10;
    for (ll i = l; i <= r; i++) {
        string cv;
        cin >> cv;
        if (cv[0] - '0' >= 0 && cv[0] - '0' < 10) {
            // int input
            continue;
        }
        else {
            if (cv == "Fizz") {
                if (ff == 1e6-1) {
                    ff = i;
                }
                else {
                    ffdist = min(ffdist, i - ff);
                }
                if (ffb != 1e6) {
                    ffdist = min(ffdist, i - ffb);
                }
            }
            else if (cv == "Buzz") {
                if (fb == 1e6) {
                    fb = i;
                }
                else {
                    fbdist = min(fbdist, i - fb);
                }
                if (ffb != 1e6) {
                    fbdist = min(fbdist, i - ffb);
                }
            }
            else {
                if (ffb == 1e6) {
                    ffb = i;
                }
                else {
                    ffbdist = min(ffbdist, i - ffb);
                }
                if (ff != 1e6-1) {
                    ffdist = min(ffdist, i - ff);
                }
                if (fb != 1e6) {
                    fbdist = min(fbdist, i - fb);
                }

            }
        }
    }
    // cout << ff << " " << ffdist << endl;
    // cout << fb << " " << fbdist << endl;
    // cout << ffb << " " << ffbdist << endl;
    if (ff != 1e6-1) {
        if (ffdist != NMAX/10) {
            // occurs more than once at this val
            ff = ffdist;
        }
    }
    if (fb != 1e6 && fbdist != NMAX/10) {
        fb = fbdist;
    }
    if (ff == 1e6-1 && ffb != 1e6) {
        // must work of conjunction
        if (ffbdist != NMAX/10) {
            ff = ffbdist;
        }
        else {
            ff = ffb;
        }
    }
    if (fb == 1e6 && ffb != 1e6) {
        // must work of conjunction
        if (ffbdist != NMAX/10) {
            fb = ffbdist;
        }
        else {
            fb = ffb;
        }
    }
    cout << ff << " " << fb << endl;
    return 0;
}