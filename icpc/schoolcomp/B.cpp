#include <bitset/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll xorbasis(vll &nums, ll n, vvll &paths) {
    vll resb(31);
    for(int i = 0; i < n; i++) {
        ll x =nums[i];
        vll cpath(1);
        cpath[0] = x;
        for (int j = 30; j >=0; j--) {
            if (x >> j& 1) {
                if (!resb[j]) {
                    resb[j] = x;
                    paths[j] = cpath;
                    break;
                }
                x ^= resb[j];
                cpath.push_back(resb[j]);
            }
        }
    }
    return resb;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, x;
    cin >> n >> x;
    vll nums(n);
    rep(i,0,n) cin >> nums[i];
    vvll paths(30);
    vll xorb = xorbasis(nums, n, paths);

    return 0;
}