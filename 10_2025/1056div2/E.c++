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
const ll MOD = 676767677, mod=1e9+7;
#define NMIN numeric_limits<int>::min()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (int &c : v) cout << c << " "


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("E.in");
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        // int ct = 0;
        unordered_map<int, int> occur;
        ll cf = 0;
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            if (n == 1) {
                cf += b - 1 == 1 ? 1 : 0;
                cf %= 2;
            }
            else if (b > 1) {
                occur[b]++;   
            }
        }
        // cout << cf << " ";
        if (n == 0 && cf != 0)
            cout << "Mimo" << endl;
        else if (n== 0)
            cout << "Yuyu" << endl;
        else {
            int ct = 0;
            for (auto &cp : occur) {
                if (cp.second % 2 == 1){
                    ct++;
                }
            }
            if (ct % 2 == 1) 
                cout << "Mimo" << endl;
            else
                cout << "Yuyu" << endl;
        }

    }
    return 0;
}