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
// #define NMAX numeric_limits<ll>::max()
// const ll MOD = 998244353, mod=1e9+7;
// #define NMIN numeric_limits<int>::min()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (int &c : v) cout << c << " "


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ifstream cin("B.in");
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> S;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            S[min(c % k, k- (c % k))]++;
        }
        bool works = true;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            c = min(c % k, k-(c% k));
            S[c]--;
            if (S[c] < 0) {
                works = false;
            }
        }
        // for (auto &cp : S) {
        //     if (cp.second != 0){
        //         works = false;
        //         break;
        //     }
        // }
        if (works)
            yes;
        else
            no;
    }
    return 0;
}