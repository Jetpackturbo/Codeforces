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
#define cout_space(v) for (int &c : v) cout << c << " "


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("C.in");
    string cs;
    cin >> cs;
    int il = cs.find("/");
    // cout << il << endl;
    int s1 = stoi(cs.substr(0, il)), s2 = stoi(cs.substr(il+1));
    if (s1 < s2 && s1 != s2-1) {
        cout << "impossible" << endl;
        return 0;
    }
    else if (s1 < s2 && s1 == s2 - 1) {
        cout << s2 << " " << s2 - 1 << endl;
        for (int i = 2; i <= s2; i++) {
            cout << 1 << " " << i << endl;
        }
        return 0;
    }
    // guaranteed that s2 >= s1
    while (s1 > s2 * (s2 -1) / 2) {
        s1 *= 2;
        s2 *= 2;
    }
    cout << s2 << " " << s2-1 << " " <<endl;
    int i =1;
    for (i = 1; i <= s2; i++) {
        cout << i << " " << i + 1 << endl;
        s1 -= i;
        if ((s2 - i) * i > s1) {
            // cout << (s2 - i) << " " << i << " " << s1 << endl;
            break;
        }
    }
    int j = i+1;
    // cout << s1 << " " << s2 << endl;
    while (s1 > s2 - j + i + 1) {
        cout << i+1 << " " << j+1  << endl;
        j++;
        s1 -= i + 1;
        // cout << s1 << " " << s2 - j + i + 1 << endl;
    }
    int cl = s1;
    // cout << (cl + s2 - j - 1) << " " << (s2 - j) << endl;
    int jr = j+1;
    while (jr < s2 ) {
        
        cout << (cl + s2 - j - 1) / (s2 - j) << " " << jr <<endl;
        jr++;
        s1 -= (cl + s2 - j - 1) / (s2 - j);
        if (s1 < s2 - jr) {
            cl = s1;
        }
    }
    if (jr == s2) {
        cout << s1 << " " << s2 << endl;
    }
    return 0;
}