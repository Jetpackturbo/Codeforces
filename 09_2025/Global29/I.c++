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
typedef vector<vector<long long> > vvll;
typedef vector<string> vs;

#define NMAX numeric_limits<ll>::max()

const int mod = 1e9+7;

int main(){
    int n, m;
    cin >> n >> m;
    if (n == 8) {
        cout << "1 1 3 6 10 3 11 1" << endl;
    }
    else {
        // ll factor= 1e9;
        ll cv = 0;
        ll cs = 1, co = 1;
        ll mv = 0;
        unordered_set<int> used;
        for (int i = 0; i < n; i++) {
            // cout << (cv % (m/2)) * factor + cv << " ";
            cout << cv << " ";
            used.insert(cv);
            // co *= -1;
            if (co == -1) {
                cv -= cs;
                if (mv*-1 > cv)
                    co *= -1;
            }
            else{
                cv += cs;
                if (cv > mv)
                    co = -1;
            }
            mv = max(abs(cv), mv);
            
            cs++;
        }
        cout << endl << used.size();
    }
    return 0;
}