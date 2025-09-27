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

const int MOD = 998244353;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> ones;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                ones.push_back(i);
        }
        bool works = true;
        vi ret(n);
        int op = 0;
        for (int i = 0; i < n; i++) {
            if (op == (int)ones.size()) {
                // no more ones left, fill with pattern
                if (i == n-1) {
                    works = false;
                    break;
                }
                ret[i] = n;
                i++;
                while(i < n) {
                    ret[i] = i;
                    i++;
                }
                break;
            }
            if (i == ones[op] - 1) {
                works = false;
                break;
            }
            if (i < ones[op]) {
                ret[i] = ones[op];
                i++;
                while(i < ones[op]) {
                    ret[i] = i;
                    i++;
                }
            }
            ret[ones[op]] = ones[op]+1;
            op++;
        }
        if (!works)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int &c : ret) {
                cout << c << " ";
            }
            cout << endl;
        }
        // for (int i = 0; i < n; i++) {
        //     if (s[i] == '0') {
        //         zeros.push_back(i+1);
        //     }
        // }
        // if (zeros.size() == 1) {
        //     cout << "NO" << endl;
        // } else {
        //     cout << "YES" << endl;
        //     vector<int> p(n+1, 0);
        //     for (int i = 1; i <= n; i++) {
        //         if (s[i-1] == '1') {
        //             p[i] = i;
        //         }
        //     }
        //     if (!zeros.empty()) {
        //         int k = zeros.size();
        //         for (int j = 0; j < k; j++) {
        //             p[zeros[j]] = zeros[(j+1) % k];
        //         }
        //     }
        //     for (int i = 1; i <= n; i++) {
        //         cout << p[i] << " ";
        //     }
        //     cout << endl;
    }
    return 0;
}