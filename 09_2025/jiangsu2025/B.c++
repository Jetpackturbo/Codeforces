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
// #define no cout<<"NO"<<endl
// #define yes cout<<"YES"<<endl
#define en end()
#define be begin()
#define fo(a,b,c) for(int i = a; i < b; i+=c)
#define srt(a) sort(a.be, a.en)
#define NMAX numeric_limits<ll>::max()
const ll MOD = 998244353, mod=1e9+7;
#define NMIN numeric_limits<int>::min()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (auto &c : v) cout << c << " "


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("B.in");
    long long n, x;
    cin >> n >> x;
    bitset<30> xb;
    long long nx = x;
    int i = 0, xbc = 0, mi = 35;
    while (nx > 0) {
        if (nx%2 == 1) {
            xb.set(i);
            xbc++;
            mi = min(mi, i);
        }
        nx /= 2;
        i++;
    }
    // cout << xbc << endl;
    int b_size = 0;
    vector<long long> basis(30);

    vvi ops;
    int cs = -1;
    bool works = true;
    for (int i = 0; i < n; i++) {
        ll cv;
        cin >> cv;
        vvi cops;
        for (int i = 0; i < 30; i++) {
            if ((cv & (1 << i)) == 0) continue; // continue if i != f(mask)
    
            if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
                basis[i] = cv;
                ++b_size;
                // cout << "added basis " << i << " " << cv << endl;
                // then we should also keep track of this in ops
                // cout << cops.size() << endl;
                for (auto &cv : cops) {
                    ops.push_back(cv);
                }
                if (i == mi)
                    cs = basis[i];
                xbc--;
                break;
            }
    
            cv ^= basis[i]; // Otherwise subtract the basis vector from this vector
            vi cadd;
            cadd.push_back(1);
            cadd.push_back(basis[i]);
            cadd.push_back(cv);
            cops.push_back(cadd);
        }
    }
    
    for (int i = mi+1; i < 30; i++) {
        if (xb.test(i)) {
            if (!basis[i]) {
                works = false;
                break;
            }
            // add this basis
            vi cadd;
            cadd.push_back(0);
            cadd.push_back(basis[i]);
            cadd.push_back(cs);
            ops.push_back(cadd);
            cs = cs | basis[i];
        }
    }
    if (!works) {
        cout << -1 << endl;
        return 0;
    }
    cout << ops.size() << endl;
    for (auto &cv : ops) {
        cout_space(cv);
        cout << endl;
    }
    
    return 0;
}