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
#define prtln cout << endl;
#define yesno(c) if (c) yes else no


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("D.in");
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vvi adj(n);
        for (int i = 0; i < n- 1; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<tuple<int, int> > q;
        q.push(make_tuple(0, 0));
        while (!q.empty()) {
            auto ctup = q.front();
            q.pop();
            int i = get<0>(ctup), ctot = get<1>(ctup);
            if (i == n - 1) {
                cout << ctot << endl;
                break;
            }
            ctot += adj[i].size() - 1;
            for (int &nc : adj[i]) {
                if (nc != i)
                    q.push(make_tuple(nc, ctot));
            }
        }
    }
    return 0;
}