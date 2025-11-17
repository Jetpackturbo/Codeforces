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
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l+r)/2;
        cout << "? " << mid << endl;
        cout.flush();
        string res;
        cin >> res;
        if (res == "YES") {
            // increase
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << "! " << l << endl;
    return 0;
}