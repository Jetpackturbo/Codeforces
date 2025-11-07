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
#define nmin numeric_limits<int>::min()
#define nmax numeric_limits<int>::max()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (int &c : v) cout << c << " "
#define prtln cout << endl;
#define yesno(c) if (c) yes else no

int main() {
    // ifstream cin("B.in");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vi ops;
        string mach;
        cin >> mach;
        bool fs = false;
        int cs = 0;
        for (int i = 0; i < n; i++) {
            if (mach[i] == 'B') {
                fs =true;
                if (cs != 0) {
                    ops.push_back(cs);
                }
                ops.push_back(-1);
                cs = 0;
            }
            else {
                cs++;
            }
        }
        if (cs != 0) {
            ops.push_back(cs);
        }
        while (q--) {
            int c;
            cin >> c;
            if (!fs) {
                cout << c << endl;
                continue;
            }
            int total = 0, i = 0;
            while (c > 0) {
                if (ops[i] == -1) {
                    c /= 2;
                    total++;
                }
                else {
                    if (c < ops[i]) {
                        total += c;
                        c = 0;
                    }
                    else {
                        total += ops[i];
                        c -= ops[i];
                    }
                }
                i++;
                i %= ops.size();
            }
            cout << total << endl;
        }
    }
    return 0;
}