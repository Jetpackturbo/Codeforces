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

vll xorbasis(vll nums, ll n) {
    vll resb(31);
    for(int i = 0; i < n; i++) {
        ll x = nums[i];
        for (int j = 30; j >= 0; j--) {
            if (x >> j & 1){
                if(!resb[j]){
                    resb[j]=x;
                    break;
                }
				else 
                    x^=resb[j];
            }
        }
    }
    return resb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("test.in");
    ll n;
    cin >> n;
    vll nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vll xorb = xorbasis(nums, n);
    ll res = 0;
    for (int i = 30; i >= 0; i--) {
        if((res>>i&1)^ 1)
            res^=xorb[i];
    }
    cout << res << endl;
    return 0;
}