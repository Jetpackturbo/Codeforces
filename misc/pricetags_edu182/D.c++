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
#define sort(a) sort(a.be, a.en)
#define NMAX numeric_limits<ll>::max()
const ll MOD = 998244353, mod=1e9+7;


int main(){
    // ifstream cin("D.in");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        ll n, y;
        cin >> n >> y;
        
        int maxp = 2;
        vll f(200001, 0);
        vll csum(200001,0);


        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            maxp = max(maxp, c);
            f[c]++;
        }
        for (int i = 1; i <= maxp; i++) {
            csum[i] = csum[i-1] + f[i];
        }
        ll maxr = numeric_limits<ll>::min();
        for (int i = 2; i <= maxp; i++) {
            ll buckets = (maxp+i -1) / i;
            ll nsum = 0;
            ll new_tickets = 0;
            // cout << maxp << " " << i << " " << buckets << endl;
            int cbl = 0, cbr = i;
            for (int j = 1; j <= buckets; j++) {
                if (cbr > maxp)
                    cbr = maxp;
                ll count = csum[cbr] - csum[cbl];
                nsum += count * j;
                new_tickets += max((ll)0, count - f[j]);
                if (cbr >= maxp)
                    break;
                cbl += i;
                cbr += i;
            }
            // cout << i << " " << nsum << " " << new_tickets << endl;
            maxr = max(maxr, nsum - (y * new_tickets));
        }
        cout << maxr << endl;
    }
    return 0;
}