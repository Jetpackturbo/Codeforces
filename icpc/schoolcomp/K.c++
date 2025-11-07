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
    // ifstream cin("K.in");
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.length();
        vvi mc = manacher(s);
        ll total = 1;
        string pat = s.substr(0,1);
        int pati = 0, patd = 1;
        for (ll i = 1; i < n; i++) {
            // cout << s[i]  << " " << pati << " " <<  pat[pati] << endl;
            if (s[i] == pat[pati]) {
                // we can continue to use current pattern
                // cout << "repeat " << pat << " " << (i+1)*pat.length();
                total ^= (i+1)*pat.length();
                pati += patd;
                if (pati < 0) {
                    pati = 1;
                    patd = 1;
                }
                else if (pati >= pat.length()) {
                    pati = pat.length() - 2;
                    patd = -1;
                }
                if (pat.length() == 1) {
                    pati = 0;
                }
            }
            else {
                // new pattern is length of minimum palindromic suffix
                // cout << s.substr(0, i + 1) << endl;
                bool found = false;
                for (int j = max((long long)pat.size(), (i+1)/2); j < i + 1; j++) {
                    // int cfi = (i-j) % 2;
                    // cout << (i-j) % 2 << " " << j + mc[1-cfi][j] << " " << i << endl;
                    
                    // if (j + mc[0][j] >= i) {

                    //     // cout << "0 case " << j << " " << mc[0][j] << " " << i << " ";
                    //     // found best
                    //     pat += s.substr(pat.size(), j+1);
                    //     cout << s.substr(0,i+1) << " " << pat << " " << j - mc[0][j] << endl;
                    //     pati = j - mc[0][j];
                    //     patd = -1;
                    //     break;
                    // }
                    if (j + mc[1][j] >= i) {
                        // cout << "1 case ";
                        // found best
                        pat += s.substr(pat.size(), j+1 - pat.size());
                        pati = 2*j - i - 1;
                        patd = -1;
                        if (pati < 0) {
                            pati *= -1;
                            patd = 1;
                        }
                        // cout << j << " " << s.substr(0,i+1) << " " << pat << " " << pati << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    pat += s.substr(pat.size(), i + 1 - pat.size());
                    pati = pat.size() - 1;
                    patd = -1;
                }
                total ^= (i+1)*pat.size();
            }
            // cout << i << " " << total << endl;
        }
        cout << total << endl;
    }
    return 0;
}