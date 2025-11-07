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
#define nmin numeric_limits<int>::min()
#define nmax numeric_limits<int>::max()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (int &c : v) cout << c << " "
#define prtln cout << endl;
#define yesno(c) if (c) yes else no

int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }
    if (b==0) {
        return a;
    }
    return gcd(b, a % b);
}

set<int> trial_division(long long n) {
    set<int> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.insert(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.insert(n);
    return factorization;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("C.in");
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        intin(a, n);
        intin(b, n);
        bool works = false;
        set<int> factors;
        for (int i = 0; i < n; i++) {
            set<int> cf = trial_division(a[i]);
            for (int c : cf) {
                if (c == 1)
                    continue;
                if (factors.find(c) != factors.end()) {
                    works = true;
                    break;
                }
                factors.insert(c);
            }
        }
        if (works) {
            cout << 0 << endl;
        }
        else {
            vti pairs;
            for (int i = 0; i < n; i++) {
                pairs.push_back(make_tuple(a[i], b[i]));
            }
            sort(pairs.be, pairs.en);
            int mdist = nmax/2;
            for (int i = 0; i < n; i++) {
                if (i != n-1 && (get<0>(pairs[i]) != 1 && get<0>(pairs[i+1]) != 1)) {
                    mdist = min(mdist, (get<0>(pairs[i+1]) - get<0>(pairs[i])) *get<1>(pairs[i]));
                }
                set<int> cf = trial_division(get<0>(pairs[i]) + 1);
                for (int c : cf) {
                    if (c == 1)
                        continue;
                    if (factors.find(c) != factors.end()) {
                        mdist = min(mdist, get<1>(pairs[i]));
                        break;
                    }
                }
            }
            if (mdist == nmax / 2) {
                srt(b);
                cout << b[0] + b[1] << endl;
            }
            else {
                cout << mdist << endl;
            }
        }
        // int ec = 0;
        // bool hasog = false, eco = false;
        // unordered_set<int> odds;
        // vi evens;
        // for (int i = 0; i < n; i++) {
        //     int c;
        //     cin >> c;
        //     a[i] = c;
        //     if (hasog || ec == 2) {
        //         continue;
        //     }
        //     if (c % 2 == 0) {
        //         ec++;
        //         if (!hasog && ec < 2) {
        //             for (int &ci : odds) {
        //                 if (gcd(ci, c) != 1) {
        //                     hasog = true;
        //                     break;
        //                 }
        //             }
        //             evens.push_back(c);
        //         }
        //     }
        //     else {
        //         if (!hasog && ec < 2) {
        //             if (odds.find(c) != odds.end()) {
        //                 hasog = true;
        //                 continue;
        //             }
        //             if (ec < 2) {
        //                 for (int &ci : evens) {
        //                     if (gcd(ci, c) != 1) {
        //                         hasog = true;
        //                         break;
        //                     }
        //                 }
        //             }
        //             if (hasog)
        //                 continue;
        //             for (int &ci : odds) {
        //                 if (gcd(ci, c) != 1) {
        //                     hasog = true;
        //                     break;
        //                 }
        //                 if (hasog) {
        //                     break;
        //                 }
        //                 if (!eco && (gcd(ci+1, c) != 1 || gcd(c+1, ci) != 1)) {
        //                     // found a one step (i.e. 3 and 11 + 1)
        //                     eco = true;
        //                 }
        //             }
        //             odds.insert(c);
        //         }
        //     }
        // }
        // intin(b, n);
        // if (ec >= 2 || hasog) {
        //     cout << 0 << endl;
        // }
        // else if (eco) {
        //     cout << 1 << endl;
        // }
        // else {
        //     // just need to make two even
        //     cout << 2 - ec << endl;
        // }
    }
    return 0;
}