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
#define prtln cout << endl;
#define yesno(c) if (c) yes else no


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("B.in");
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi nums(n);
        intin(nums, n);
        ll count = 0;
        int cmax = 0;
        for (int i = 0; i < n; i++) {
            cmax = max(cmax, nums[i]);
            if (i % 2 == 1) {
                nums[i] = cmax;
            }
            // if (i % 2 == 0) {
            //     // less than the next
            //     if (nums[i] == nums[i+1]) {
            //         if (nums[i] == cmax) {
            //             count++;
            //             // decrement i
            //         }
            //         else {
            //             nums[i+1] = cmax;
            //         }
            //     }
            //     else if (nums[i] > nums[i+1]) {
            //         // necessarily nums[i+1] < cmax
            //         nums[i+1] = cmax;
            //     }
            // }
            // else {
            //     // more than the next
            //     if (nums[i] == nums[i+1]) {
            //         if (cmax == nums[i]) {
            //             count++;
            //             nums[i+1]--;
            //         }
            //     }
            //     else if (nums[i] < nums[i+1]) {
            //         if (cmax == nums[i]) {
            //             count += nums[i+1] - nums[i] + 1;
            //             nums[i+1] = nums[i] - 1;
            //         }
            //     }
            // }
        }
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0) {
                // less than next
                if (nums[i] == nums[i+1]) {
                    count++;
                }
            }
            else {
                // more than next
                if (nums[i] <= nums[i+1]) {
                    count += nums[i+1] - nums[i] + 1;
                    nums[i+1] = nums[i] - 1;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}