#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll nearest(set<ll> &l1, ll pf) {
    auto lba = l1.lower_bound(pf);
    if (lba == l1.end())
        lba = prev(lba);
    ll l1b = *lba;
    if (l1b != pf && lba != l1.begin()) {
        // we want to see if there is a smaller than this that is closer
        if (abs(l1b - pf) >= abs(pf - *prev(lba))) {
            l1b = *prev(lba);
        }
    }
    return l1b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("test.in");
    ll n, k, m, C;
    cin >> n >> k >> m >> C;
    
    map<ll, set<ll> > rowc;
    set<ll> rc;
    for (int i = 0; i < n; i++) {
        rc.insert(i+1);
    }
    rowc[0] = rc;
    for (int i = 0; i < m; i++) {
        ll pf;
        cin >> pf;
        
        // at any point, we only must evaluate the ones with min width and next lowest width
        ll minc = rowc.begin()->first;
        auto it = rowc.begin();
        ll bestd = -1, loc = -1, level = -1;
        for (int j = 0; j < 30; j++) {
            if (rowc.find(minc+j) == rowc.end()) {
                continue;
            }
            ll mcd = (it)->first;
            set<ll>& l1 = (it)->second;
            ll l1b = nearest(l1, pf);
            ll cd = (C - abs(l1b - pf)) << (29 - j);
            if (cd > bestd) {
                loc = l1b;
                level = mcd;
                bestd = cd;
                // cout << "found new best loc " << loc << " " << level << endl;
            }
            else if (cd == bestd && l1b < loc) {
                loc = l1b;
                level = mcd;
                // cout << "found new tie loc " << loc << " " << level << endl;
            }
            it++;
        }
        cout << loc << " ";
        rowc[level].erase(loc);
        if (level < k - 1) {
            if (rowc.find(level+1) == rowc.end()) {
                set<ll> news;
                news.insert(loc);
                rowc[level+1] = news;
            }
            else {
                rowc[level+1].insert(loc);
            }
        }
        if (rowc[level].size() == 0) {
            rowc.erase(level);
        }
    }
    cout << endl;
    return 0;
}