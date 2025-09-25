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
#define endl '\n'
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define en end()
#define be begin()
#define sort(a) sort(a.be, a.en)
#define NMAX numeric_limits<ll>::max()
const ll MOD = 998244353, mod=1e9+7;


int main(){
    // ifstream cin("D.in");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        ll a, b;
        cin >> a >> b;
        if (b % 2 == 1) {
            if (a % 2 == 0) {
                cout << -1 << endl;
                continue;
            }
            cout << a * b + 1 << endl;
        }
        else {
            // b even
            if (a % 2 == 1 && b % 4 != 0) {
                cout << -1 << endl;
                continue;
            }
            // both even
            cout << (a*b/2) + 2 << endl;
        }
    }
    return 0;
}