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
    ifstream cin("F.in");
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vi nums(n);
        vi lpeaks;
        vi rpeaks;
        int ph = -1;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] >= ph) {
                ph = nums[i];
                lpeaks.push_back(i);
            }
        }
        int rph = -1;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] >= rph) {
                rph = nums[i];
                rpeaks.push_back(i);
                if (rph == ph) {
                    break;
                }
            }
        }
        // note ph stores max height
        ll lsum = 1;
        for (int i = 0; i < lpeaks.size() - 1; i++) {

        }

        cout << (lsum * rsum) % mod << endl;
    }
    return 0;
}