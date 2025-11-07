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

vvi manacher(const string& s) {
    int n = sz(s);
    vvi p(2);
    p[0] = vi(n+1);
    p[1] = vi(n);
    rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++ ){
        int t = r- i + !z;
        if (i<r){
            p[z][i]= min(t, p[z][l+t]);
        }
        int L = i-p[z][i], R = i + p[z][i] -!z;
        while (L >=1 && R+1 < n && s[L-1] == s[R+1]) {
            p[z][i]++;
            L--;
            R++;
        }
        if (R>r){
            l = L;
            r = R;
        }
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("c.in");
    string s;
    cin >> s;
    int n = s.size();
    vi ret(n, 1);
    vvi mc = manacher(s);
    // for (vi &m : mc) {
    //     for (int &c : m) {
    //         cout << c <<  " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < n; i++) {
        int me = mc[0][i+1], mo = mc[1][i];
        while (me >= 0 && ret[me + i] < me*2) {
            ret[me + i] = me*2;
            me--;
        }
        while (mo >= 0 && ret[mo+ i] < mo*2 + 1) {
            ret[mo + i] = mo*2+1;
            mo--;
        }
        // ret[me + i] = max(ret[me + i], me*2);
        // ret[mo + i] = max(ret[mo + i], mo*2+1);
    }
    rep(i, 0, n) cout << ret[i] << " ";
    cout << endl;
    return 0;
}