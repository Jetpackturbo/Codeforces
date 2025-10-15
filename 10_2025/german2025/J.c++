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

// #define endl '\n'
#define no cout<<"no"<<endl
#define yes cout<<"yes"<<endl
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
    // ifstream cin("J.in");
    string op, s;
    int n;
    cin >> op >> n >> s;
    if (op == "Encode") {
        if (n == 1) {
            cout << s << endl;
            return 0;
        }
        string res = "";
        if (s[0] == '0') {
            res += "2" + s.substr(1);
            cout << res << endl;
        }
        else {
            // now we must check if there are more than one 1 in this thing
            int hn1 = -1;
            bool hp = false;
            fo(1, n, 1) {
                if (s[i] == '1' && hn1 == -1) {
                    hn1 = i;
                }
                else if (s[i] == '1') {
                    hp = true;
                    break;
                }
            }
            if (hn1 == -1) {
                cout << s << endl;
            }
            else {
                if (!hp) {
                    // now we need to do encode 3 twos
                    if (hn1 == 1) {
                        // encode two rest 0s
                        cout << "22";
                        fo(2, n, 1)
                            cout << "0";
                    }
                    else if (hn1 == n-1) {
                        if (n == 3) {
                            cout << "222" << endl;
                            return 0;
                        }
                        cout << "2222";
                        fo(4,n,1)
                            cout << "0";
                        cout << endl;
                        return 0;
                    }
                    else {
                        cout << "22";
                        cout << s.substr(2, hn1 - 2) + "2" + s.substr(hn1+1);
                    }
                }
                else {
                    res = "2" + s.substr(1, hn1 - 1) + "2" + s.substr(hn1+1);
                    cout << res << endl;
                }
            }
        }
    }
    else {
        if (n == 1) {
            cout << s << endl;
            return 0;
        }
        int loc2 = s.find("2");
        if (loc2 == string::npos) {
            cout << "1";
            fo(1,n,1)
                cout<<"0";
            return 0;
        }
        if (loc2 == n - 1) {
            // starts with 0
            // and everything else in order
            // cout << "here" << endl;
            cout << "0" + s.substr(0, n-1) << endl;
            return 0;
        }
        int ll2 = s.substr(loc2 + 1).find("2");
        if (ll2 == string::npos) {
            // starts with 0
            cout << "0" + s.substr(loc2+1) + s.substr(0, loc2) << endl;
        }
        else {
            ll2 += loc2 + 1;
            // cout << loc2 << " " << ll2 << endl;
            int f1 = s.find("1");
            if (f1 == string::npos) {
                //we are in the 3 twos case
                int l3 = s.substr(ll2+1).find("2");
                // cout << l3 << endl;
                if (l3 == string::npos) {
                    cout << "11";
                    fo(2,n,1)
                        cout << "0";
                    cout << endl;
                    return 0;
                }
                else {
                    l3 += ll2 + 1;
                    int l4 = s.substr(l3+1).find("2");
                    if (l4 != string::npos) {
                        cout << "1";
                        fo(1,n-1,1)
                            cout << "0";
                        cout << "1" << endl;
                        return 0;
                    }
                    else {
                        cout << "10";
                        if (ll2 - loc2 == 1) {
                            // then loc2 is our starting point
                            fo(ll2+1, l3, 1) {
                                cout << "0";
                            }
                            cout << "1";
                            fo(l3+1,n, 1)
                                cout << "0";
                            fo(0,loc2, 1)
                                cout << "0";
                            cout << endl;
                        }
                        else if (l3 - ll2 == 1) {
                            // then ll2 is our starting point
                            fo(l3+1,n, 1)
                                cout << "0";
                            fo(0,loc2, 1)
                                cout << "0";
                            cout << "1";
                            fo(loc2+1, ll2, 1) {
                                cout << "0";
                            }
                            cout << endl;
                        }
                        else {
                            // must have started at l3
                            fo(1, ll2, 1)
                                cout << "0";
                            cout << "1";
                            fo(ll2+1, n-1, 1) {
                                cout << "0";
                            }
                            cout << endl;
                        }
                    }
                }
            }
            else {
                if (!(f1 > loc2 && f1 < ll2)) {
                    cout << "1";
                    for(int i = loc2+1; i < ll2; i++){
                        cout << s[i];
                    }   
                    cout << "1";
                    for(int i = ll2+1; i < n; i++){
                        cout << s[i];
                    }
                    for (int i = 0; i < loc2; i++) {
                        cout << s[i];
                    }
                    cout << endl;
                }
                else {
                    // then it ust be that the first two we see is the second overall
                    cout << "1";
                    for(int i = ll2+1; i < n; i++){
                        cout << s[i];
                    }
                    for (int i = 0; i < loc2; i++) {
                        cout << s[i];
                    }
                    cout << "1";
                    for(int i = loc2+1; i < ll2; i++){
                        cout << s[i];
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}