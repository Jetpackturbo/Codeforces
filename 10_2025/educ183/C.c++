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
typedef vector<vector<ll> > vvll;
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
#define NMIN numeric_limits<int>::min()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (int &c : v) cout << c << " "


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("C.in");
    int T;
    cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ca = count(s.begin(), s.end(), 'a');
        int cb = n - ca;
        if (ca == cb) {
            cout << 0 << endl;
            continue;
        }
        // char major = (ca > cb ? 'a' : 'b');
        int target = ca - cb;

        int pref = 0;
        unordered_map<int,int> earliest;
        earliest[0] = -1;
        int mlen = n;
        for (int i = 0; i < n; i++) {
            pref += (s[i] == 'a' ? 1 : -1);
            int need = pref - target;
            if (earliest.count(need)) {
                // cout << "found" << need << endl;
                mlen = min(mlen, i - earliest[need]);
            }
            if (!earliest.count(pref))
                earliest[pref] = i;
        }
        // // int ac = 0, bc = 0, las = 0, lbs = 0;
        // //int pv = -1, ps = 0;
        // vi acs(n, 0), bcs(n, 0);
        // unordered_map<int, int> diffs;
        // fo(0,n,1) {
        //     if (s[i] == 'b') {
        //         bcs[i]++;
        //         // if (pv == 1) {
        //         //     ps++;
        //         //     lbs = max(lbs, ps);
        //         // }
        //         // else {
        //         //     pv = 1;
        //         //     ps = 1;
        //         //     lbs = max(lbs, ps);
        //         // }
        //     }
        //     else {
        //         acs[i]++;
        //         // if (pv == 0) {
        //         //     ps++;
        //         //     las = max(las, ps);
        //         // }
        //         // else {
        //         //     pv = 0;
        //         //     ps = 1;
        //         //     las = max(las, ps);
        //         // }
        //     }
        //     if (i > 0){
        //         acs[i] += acs[i-1];
        //         bcs[i] += bcs[i-1];
        //     }
        // }
        // if (acs[n-1] == 0 || bcs[n-1] == 0) {
        //     cout << -1 << endl;
        //     continue;
        // }
        // if (acs[n-1] == bcs[n-1]) {
        //     cout << 0 << endl;
        //     continue;
        // }
        // diffs[0] = -1;
        // int mlen = n;
        // int tdiff = abs(acs[n-1] - bcs[n-1]);
        // // cout << tdiff << endl;
        // for (int i = 0; i < n; i++) {
        //     int li = acs[i] - bcs[i];
            
        //     if ( diffs.find(tdiff - li) != diffs.en) {
        //         cout << "found" << tdiff - li << " " << li <<endl;
        //         mlen = min(mlen, i - diffs[tdiff - li]);
        //     }
        //     if (diffs.find(acs[i] - bcs[i]) == diffs.end())
        //         diffs[acs[i] - bcs[i]] = i;
        // }
        if (mlen == n)
            cout << -1 <<endl;
        else {
            cout << mlen << endl;
        }
        /*
        if (ac - bc > 0) {
            if (las >= ac - bc) {
                cout << ac - bc << endl;
            }
            else {
                // see if we can remove a non-contiguous block
                int l = 0, r = n-1, cac= ac, cbc =bc;
                int msr = n;
                while (r - l + 1 >= ac - bc) {
                    if (cac - cbc == ac - bc) {
                        // cout << "found" << l << " " << r << endl;
                        msr = min(msr, r - l + 1);
                    }
                    if (cac - cbc >= ac - bc) {
                        if (s[l] == 'a') {
                            l++;
                            cac--;
                        }
                        else if (s[r] == 'a') {
                            r--;
                            cac--;
                        }
                        else {
                            l++;
                            cbc--;
                        }
                    }
                    else {
                        if (s[l] == 'b') {
                            l++;
                            cbc--;
                        }
                        else if (s[r] == 'b') {
                            r--;
                            cbc--;
                        }
                        else {
                            l++;
                            cac--;
                        }
                    }
                }
                if (msr == n)
                    cout << -1 << endl;
                else
                    cout << msr << endl;
            }
        }
        else {
            if (lbs >= bc - ac) {
                cout << bc - ac << endl;
            }
            else {
                int l = 0, r = n-1, cac= ac, cbc =bc;
                int msr = n;
                while (r - l + 1 >= bc - ac) {
                    if (cbc - cac == bc - ac) {
                        // cout << "found" <<l << " " << r << endl;
                        msr = min(msr, r - l + 1);
                    }
                    if (cbc - cac < bc - ac) {
                        if (s[l] == 'a') {
                            l++;
                            cac--;
                        }
                        else if (s[r] == 'a') {
                            r--;
                            cac--;
                        }
                        else {
                            l++;
                            cbc--;
                        }
                    }
                    else {
                        if (s[l] == 'b') {
                            l++;
                            cbc--;
                        }
                        else if (s[r] == 'b') {
                            r--;
                            cbc--;
                        }
                        else {
                            l++;
                            cac--;
                        }
                    }
                }
                if (msr == n)
                    cout << -1 << endl;
                else
                    cout << msr << endl;
            }
        }
    */
    }
    return 0;
}