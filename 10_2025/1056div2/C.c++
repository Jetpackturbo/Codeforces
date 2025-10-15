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
const ll MOD = 676767677, mod=1e9+7;
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
        vi nums(n);
        intin(nums, n);
        int px = 0;
        int f = 0;
        // first is an R cape
        vi cd(n, 0), ld(n, 0), rd(n, 0);
        rd[0] = 1;
        bool works = true;
        for (int i = 1; i < n; i++) {
            if (1 + nums[i] - nums[i-1]  > 2 || 1 + nums[i] - nums[i-1] < 0) {
                works = false;
                break;
            }
            if (1 + nums[i] - nums[i-1] == px) {
                px = 0;
            }
            else if (1 + nums[i] - nums[i-1] == px + 1) {
                px = 1;
                // cd[i]++;
            }
            else {
                works = false;
                break;
            }
        }
        // for (int i = 1; i < n; i++) {
        //     ld[i] += ld[i-1] + cd[i];
        //     rd[n - i -1] += rd[n - i] + (1 - cd[n-i]); 
        // }
        // for (int i = 0; i < n; i++) {
        //     if (ld[i] + rd[i] != nums[i]) {
        //         works = false;
        //         break;
        //     }
        // }
        if (works) {
            f++;
        }
        works = true;
        px = 1;
        for (int i = 1; i < n; i++) {
            if (1 + nums[i] - nums[i-1]  > 2 || 1 + nums[i] - nums[i-1] < 0) {
                works = false;
                break;
            }
            if (1 + nums[i] - nums[i-1] == px) {
                px = 0;
            }
            else if (1 + nums[i] - nums[i-1] == px + 1) {
                px = 1;
            }
            else {
                works = false;
                break;
            }
        }
        if (works) {
            f++;
        }
        cout << f << endl;
    }
    return 0;
}