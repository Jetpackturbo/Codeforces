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

vi Z(const string &s) {
    vi z(sz(s));
    int l = -1, r= -1;
    rep(i,1,sz(s)) {
        z[i] = i >= r ? 0 : min(r-i, z[i-l]);
        while (i + z[i] < sz(s) && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("c.in");
    int mod = 1e9+7;
    int n;
    cin >> n;
    string s;
    cin >> s;
    // vi zfunc = Z(s);
    // for (int &c : zfunc) {
    //     cout << c << " ";
    // }
    // cout << endl;
    int m = sz(s);
    if (m > n) {
        cout << 0 << endl;
        return 0;
    }
    int period = m;
    string ns = s.substr(1) + s[m-1];
    for (int i = 1; i < m; i++) {
        if (ns == s) {
            period = min(period, i);
            break;
        }
        ns = s.substr(i + 1) + s.substr(m - i - 1);
    }
    // cout << period << endl;
    ll total = 1;
    for (int i = 0; i < n - m; i++) {
        total *= 26;
        total %= mod;
    }
    total *= (n - m + 1);
    total %= mod;
    // now we must remove overcounting
    for (int i = 0; i < (n / m) - 1; i++) {
        
    }
    cout << total << endl;
    return 0;
}