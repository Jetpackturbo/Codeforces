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
#define nmax numeric_limits<int>::max()
const ll MOD = 998244353, mod=1e9+7;
#define NMIN numeric_limits<int>::min()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (int &c : v) cout << c << " "

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("narrowing_down_input.txt");
    ofstream cout("C.out");
    int T;
    cin >> T;
    for (int testc = 1; testc <= T; testc++) {
        ll n;
        cin >> n;
        unordered_map<ll,ull > nums;
        ll prev = 0;
        ull count = n*(n+1)*(n+2)/6;
        nums[0] = 1;
        for (int i = 0; i < n; i++) {
            ll c;
            cin >> c;
            c ^= prev;
            nums[c]++;
            prev = c;
        }
        for (auto &cp : nums) {
            count -= cp.second * (cp.second * cp.second-1) / 6;
        }
        cout << "Case #" << testc << ":" << count << endl;
    }
    return 0;
}