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
struct mi {
    int v; explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(ll _v) :v(_v% MOD) { v += (v < 0) * MOD; }
};
mi& operator+=(mi& a, mi b) {
    if ((a.v += b.v) >= MOD) a.v -= MOD;
    return a;
}
mi& operator-=(mi& a, mi b) {
    if ((a.v -= b.v) < 0) a.v += MOD;
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pow(mi a, ll p) {
    return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {  return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }

int main(){
    ifstream cin("F.in");
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vi nums(n);
        vti lpeaks;
        vti rpeaks;
        int ph = -1;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] > ph) {
                ph = nums[i];
                lpeaks.push_back(make_tuple(i,1));
            }
            else if (nums[i] == ph) {
                lpeaks[lpeaks.size()-1] = make_tuple(ph, 1 + get<1>(lpeaks[lpeaks.size()-1]));
            }
        }
        int rph = -1;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] > rph) {
                rph = nums[i];
                rpeaks.push_back(make_tuple(i,1));
            }
            else if (nums[i] == rph) {
                rpeaks[rpeaks.size()-1] = make_tuple(rph, 1 + get<1>(rpeaks[rpeaks.size()-1]));
            }
            if (nums[i] == ph) {
                break;
            }
        }
        // note ph stores max height
        mi lsum = 1;
        mi rsum = 1;
        for (int i = 0; i < lpeaks.size() - 1; i++) {
            // note first one should be zero
            lsum *= pow(mi(2), get<0>(lpeaks[i+1]) - get<0>(lpeaks[i]) - 1);
            if (get<1>(lpeaks[i]) > 0 ){
                
            }

        }
        cout << lsum.v << " " << rsum.v << endl;
        cout << (lsum * rsum).v << endl;
    }
    return 0;
}