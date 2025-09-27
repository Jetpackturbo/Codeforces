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
typedef vector<vector<long long> > vvll;
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

#define cout_space(v) for (auto &c : v) cout << c << " "

int main(){
    // ifstream cin("D.in");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        ll n, k;
        cin >> n >> k;
        if (k >= n) {
            cout << n * 3 << endl;
            continue;
        }

        // ll total = 0;
        // ll cn = n;
        // ll ci = 0, cv = 1;
        // ll ca = 0;
        // priority_queue<ll> cr;
        // while (cn > 0) {
        //     ca += cn % 3;
        //     total += (cn % 3) * (cv*3 + ci * cv/3);
        //     fo(0, cn % 3, 1)
        //         cr.push(cv/3);
        //     ci++;
        //     cv *= 3;
        //     cn /= 3;
        // }
        // if (ca > k) {
        //     cout << -1 << endl;
        //     continue;
        // }
        // ll diff = (k - ca);
        
        // for (int j = 0; j < diff - 1; j+= 2 ) {
        //     if(diff - j < 2)
        //         break;
        //     ll cc = cr.top();
        //     total -= cc;
        //     cr.pop();
        //     fo(0,3,1)
        //         cr.push(cc/3);
        // }
        // cout << total << endl;
    }
    return 0;
}