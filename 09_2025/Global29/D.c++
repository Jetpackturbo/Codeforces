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

const int MOD = 998244353;

int main(){
    int t; 
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        int n;
        cin >> n;
        unordered_map<int, int> counts;
        for (int i = 0; i< n; i++) {
            int c;
            cin >> c;
            counts[c]++;
        }
        vti sv;
        for (auto cp: counts) {
            sv.push_back(make_tuple(cp.second, cp.first));
        }
        sort(sv.begin(), sv.end(), greater<tuple<int,int>>());
        int op = 0;
        ll at = 0, bt = 0;
        for (auto &ct : sv) {
            int opt = get<0>(ct), val = get<1>(ct);
            if (val % 2 == 1) {
                if (op == 0) {
                    at += val*((opt+1)/2);
                    bt += val*(opt/2);
                    op = 1;
                }
                else {
                    bt += val*((opt+1)/2);
                    at += val*(opt/2);
                    op = 0;
                }
            }
            else {
                at += val*(opt/2);
                bt += val*(opt/2);
            }
        }
        cout << at << " " << bt << endl;
    }
    return 0;
}