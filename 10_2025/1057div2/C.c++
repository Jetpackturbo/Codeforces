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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("C.in");
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        unordered_map<ll, ll> sticks;
        // intin(sticks, n);
        fo(0,n,1) {
            int c;
            cin >> c;
            sticks[c]++;
        }
        ll maxp = 0, curp = 0, cpa = 0;
        vll maxmt;
        for (auto &cp : sticks) {
            curp += (cp.second - cp.second % 2) * cp.first;
            // here is where we do a max side length
            cpa += cp.second - cp.second % 2;
            if (cp.second % 2 == 1) {
                maxmt.push_back(cp.first);
            }
        }
        if (cpa > 2)
            maxp = curp;
        srt(maxmt);
        for (int i = maxmt.size()-1; i >= 0; i--) {
            if (curp > maxmt[i]) {
                maxp = curp + maxmt[i];
                break;
            }
        }
        for(int i = maxmt.size() - 2; i >= 0; i--) {
            if (curp + maxmt[i] > maxmt[i+1]) {
                // cout << maxp << " " <<  maxmt[i] << " " <<  maxmt[i+1] << endl;
                maxp = max(maxp, curp + maxmt[i] + maxmt[i+1]);
                break;
            }
        }
        cout << maxp << endl;
    }
    return 0;
}