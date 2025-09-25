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

#define NMAX numeric_limits<ll>::max()

const ll MOD = 998244353;

int main(){
    ifstream cin("D.in");
    int T;
    cin >> T;
    while(T--){
        ll n, y;
        cin >> n >> y;
        vi nums(n);
        int maxp = -1;
        unordered_map<int, int> f;

        for (int i =0; i < n; i++) {
            cin >> nums[i];
            maxp = max(maxp, nums[i]);
            f[nums[i]]++;
        }
        vi csum(maxp+2,0);
        for (int i = 1; i <= maxp; i++) {
            csum[i] = csum[i-1] + f[i];
        }
        ll maxr = numeric_limits<ll>::min();
        for (int i = 2; i <= maxp+1; i++) {
            ll buckets = (maxp+i -1) / i;
            ll nsum = 0;
            ll new_tickets = 0;
            for (int j = 1; j <= buckets; j++) {
                int cbl = ((j-1) * (i))+1, cbr = min(j * i,maxp); 
                ll count = csum[cbr] - csum[cbl-1];
                nsum += count * j;
                new_tickets += max((ll)0, count - f[j]);
            }
            // cout << i << " " << nsum << " " << new_tickets << endl;
            maxr = max(maxr, nsum - y * (new_tickets));
        }
        cout << maxr << endl;
    }
    return 0;
}