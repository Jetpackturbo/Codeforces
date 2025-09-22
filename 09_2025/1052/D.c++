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

const int MOD = 998244353;

int main(){
    // ifstream cin("E.in");
    int T;
    cin >> T;
    while(T--){
        int l, r;
        cin >> l >> r;
        // precalc total
        cout << r*(r+1) - l*(l+1) <<endl;
        
        int tp = 1;
        int cr = r;
        while (cr > 0) {
            tp*=2;
            cr >>= 1;
        }
        // if (r != bitcount-1)
        //     bitcount /= 2;
        // cout << "reached " << r << " " << l << endl;
        vi ret((size_t)(r - l+1), 0);
        // cout << "after arr " << endl;
        unordered_set<int> found;
        for (int i = r; i >= l; i--) {
            if (found.find(i) != found.end()) {
                continue;
            }
            cout << i -l << " " << tp -1 - i- l << endl;
            ret[i - l] = tp - 1 - i;
            ret[tp - 1 - i - l] = i;
            found.insert(i);
            found.insert(tp -1 -i);
            // if (tp == i) {
            //     tp /= 2;
            // }
        }
        for (int &c : ret) 
            cout << c << " ";        
        cout << endl;
    }
    return 0;
}