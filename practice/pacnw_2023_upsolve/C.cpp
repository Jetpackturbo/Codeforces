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
typedef vector<ll> vll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("test.in");
    ll n, k;
    cin >> n >> k;
    vll nums(n);
    ll ctotal = 0, maxn = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        ctotal += nums[i];
        maxn = max(nums[i], maxn);
    }
    ll mb = max((ctotal +k - 1) / k, maxn);
    cout << mb * k - ctotal << endl;
    return 0;
}