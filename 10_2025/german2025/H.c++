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
#define no cout<<"no"<<endl
#define yes cout<<"yes"<<endl
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
    ifstream cin("H.in");
    int n, m;
    cin >> n >> m;
    vvi paths(n);
    fo(0,m,1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
    }
    int a, b;
    cin >> a >> b;
    unordered_set<int> avis;
    queue<int> bfs;
    bfs.push(a-1);
    while (!bfs.empty()) {
        int c = bfs.front();
        bfs.pop();
        if (avis.find(c) != avis.end())
            continue;
        avis.insert(c);
        for (auto &cc : paths[c]) {
            if (avis.find(cc) == avis.end()) {
                bfs.push(cc);
            }
        }
    }

    bfs.push(b-1);
    bool works = false;
    unordered_set<int> bvis;
    while(!bfs.empty()) {
        int c =bfs.front();
        bfs.pop();
        if (avis.find(c) != avis.end()) {
            yes;
            cout << c+1 << endl;
            works = true;
            break;
        }
        if (bvis.find(c) != bvis.end()) {
            continue;
        }
        bvis.insert(c);
        for (auto &cc : paths[c]) {
            if (bvis.find(cc) == bvis.end()) {
                bfs.push(cc);
            }
        }
    }
    if (!works) {
        no;
    }
    return 0;
}