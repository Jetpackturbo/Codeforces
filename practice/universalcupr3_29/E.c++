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
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
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
#define yesno(c) if (c) yes; else no


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("E.in");
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vvi paths(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            paths[a].push_back(b);
            paths[b].push_back(a);
        }
        bool works = true;
        // int d2c = 0;
        // for (int i = 0; i < n; i++) {
        //     if (paths[i].size() > 2) {
        //         d2c++;
        //     }
        // }
        vi depth(n, -1);
        stack<tuple<int, int, int> > s;
        int cd = -1;
        s.push(make_tuple(0,0, -1));
        while (!s.empty()) {
            if (!works)
                break;
            auto cc = s.top();
            int cs = get<0>(cc), cdep = get<1>(cc), cpar = get<2>(cc);
            s.pop();
            if (depth[cs] != -1)
                continue; 
            depth[cs] = cdep;
            for (int &nc: paths[cs]) {
                if (nc == cpar)
                    continue;
                if (depth[nc] != -1) {
                    if (cd == -1) {
                        cd = depth[cs] - depth[nc];
                        // cout << "init cd " << cs << " " << nc << "  " << cd << endl;
                    }
                    else {
                        if (cd != depth[cs] - depth[nc]) {
                            // cout << "broken depth " << cs << " " << nc << depth[cs] << " " << depth[nc] << endl;
                            works = false;
                            break;
                        }
                    }
                }
                else {
                    s.push(make_tuple(nc, cdep+1, cs));
                }
            }
        }
        // if (cd != -1 && d2c > 2)
        //     works = false;
        yesno(works);
    }
    return 0;
}