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
    vector<int> ret(n, 0);
    int bc = 0, cn = n;
    while (cn > 0) {
        cn /= 2;
        bc++;
    }
    for (int i = 0; i < bc;  i++) {
        // construct string
        string ask = "";
        for (int j = 1; j <= n; j++) {
            if (((j >> (i)) & 1) == 1) {
                ask += "1";
            }
            else ask += "0";
        }
        cout << "? " << ask << endl;
        cout.flush();
        string res;
        cin >> res;
        for (int j = 0; j < n; j++) {
            if (res[j] - '0' == 1) {
                ret[j] |= (1 << i);
            }
        }
    }
    cout << "! ";
    for (int &c : ret)
        cout << c << " ";
    cout << endl;
    return 0;
}