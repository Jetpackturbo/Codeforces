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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("test.in");
    int n;
    cin >> n;
    vi nums(n);
    priority_queue<pair<int,int>> pq;
    int nz = 0, maxz = 0, tz = 0;
    rep(i,0,n) {
        cin >> nums[i];
        nz += nums[i] == 0 ? 0 : 1;
        maxz = max(nums[i], maxz);
        tz += nums[i];
        if (nums[i] != 0)
            pq.push(make_pair(nums[i], i));
    }
    if (maxz > nz - 1 || tz % 2 == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << tz / 2 << endl;
    while (!pq.empty()) {
        auto cp = pq.top();
        pq.pop();
        int cv = cp.first, ci = cp.second;
        vector<pair<int,int> > repop;
        for (int i = 0; i < cv; i++) {
            auto ccp = pq.top();
            pq.pop();
            ccp.first--;
            cout << ci + 1 << " " << ccp.second + 1 << endl;
            if (ccp.first != 0) {
                repop.push_back(ccp);
            }
        }
        for (auto ctp : repop)
            pq.push(ctp);
    }
    return 0;
}