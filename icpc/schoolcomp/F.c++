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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("F.in");
    int T;
    cin >> T;
    ll maxnum = numeric_limits<ll>::max() / 10;
    while (T--) {
        int n, a, b, s;
        cin >> n >> a >> b >> s;
        ll oa = 0, op = 0;
        vector<ll> pt(n,0);
        vector<ll> mp(n, maxnum);
        vector<bool> solved(n, false);
        for (int i = 0; i < s; i++) {
            int t;
            char p;
            string res;
            cin >> t >> p >> res;
            int pi = p - 'A';
            if (solved[pi]) {
                continue;
            }
            if (res == "ac") {
                solved[pi] = true;
                oa++;
                op += t + 20*pt[pi];
            }
            else if (res == "rj") {
                pt[pi]++;
            }
            else if (res == "pd" && mp[pi] == maxnum){
                // pending take best
                mp[pi] = min(t + 20*pt[pi], mp[pi]); 
            }
        }
        if ((oa == a && op < b) || oa > a) {
            cout << 0 << endl;
            continue;
        }
        bool works = false;
        int count = 0;
        sort(mp.begin(), mp.end());
        for (int i = 0; i < n; i++) {
            if (mp[count] == maxnum) {
                break;
            }
            oa++;
            op += mp[count];
            count++;
            if (oa > a || (oa == a && op < b)) {
                works = true;
                break;
            }
        }
        // cout << oa << " " << op << endl;
        if ((oa == a && op < b) || oa > a) {
            works = true;
        }
        if (works) {
            cout << count << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}