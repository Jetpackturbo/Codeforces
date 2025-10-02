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
#define cout_space(v) for (auto &c : v) cout << c << " "


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("E.in");
    int n;
    cin >> n;
    vvi colors(2, vi(n));
    vb used(n*2+1, false);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> colors[i][j];
            used[colors[i][j]] = true;
        }
    }
    int up = 1;
    fo(0,2,1)
        for(int j = 0; j < n; j+=1) {
            if (colors[i][j] == 0) {
                while (used[up])
                    up++;
                colors[i][j] = up;
                up++;
            }
        }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << colors[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}