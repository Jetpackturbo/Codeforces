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

#define rep(i,a,b) for(int i=a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

ll solve(ll n) {
    if (n == 0)
        return 0;
    ll bz = 0, bl =0, cn = n, ctp = 1, rem = 0;
    while (cn > 0) {
        bl++;
        ctp *= 2;
        if (cn % 2 == 0) {
            bz = bl;
            rem = n % ctp; 
        }
        cn /= 2;
    }
    ctp /= 2;
    ctp *= bl;
    ctp -= ;
    // cout << ctp << endl;
    return ctp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("test.in");
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}