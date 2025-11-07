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
    ifstream cin("c.in");
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < m; i++ ) {
        int c;
        cin >> c;
        if (c == 2) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            bool isPal = true;
            for (int i = a; i <= b/2; i++) {
                
            }
        }
        else {
            int k;
            char c;
            cin >> k >> c;
            k--;
            s[k] = c;
        }
    }
    return 0;
}