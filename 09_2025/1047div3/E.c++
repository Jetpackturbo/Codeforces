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
#define fo(a,b,c) for(int i = a; i < b; i+=c)
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
        int n, k;
        cin >> n >> k;
        ll total = 0, risct = 0;
        vi count(n+1, 0);
        fo(0, n, 1) {
            int c;
            cin >> c;
            count[c]++;
        }
        ll global_mex = -1;
        int stablec = 0;
        int r1sc = 0;
        bool stable = true;
        ll minnc = NMAX;
        fo(0,n+1,1) {
            if (count[i] == 0) {
                global_mex = i;
                break;
            }
            else if (count[i] == 1 && stable) {
                // solos under global mex are steady
                stablec++;
                total += i;
            }
            else if (count[i] == 1) {
                r1sc++;
                risct += i;
            }
            else {
                if (stable)
                    minnc = i;
                stable = false;
            }
        }
        if (minnc <= global_mex && k > 1) {
            // fix parity to account for intermediary switch
            k++;
        }
        minnc = min(minnc, global_mex);
        if (n -stablec == 0) {
            // all stable
            cout << total << endl;
            continue;
        }
        if (n - stablec == 1) {
            // guy above global mex will revert to global mex
            total += global_mex;
            cout << total << endl;
            continue;
        }
        // case work on k:
        if (k == 1) {
            total += risct;
            total += (n-stablec-r1sc) * global_mex;
            cout << total << endl;
            continue;
        }
        if (k % 2 == 1) {
            total += (n-stablec) * minnc;
        }
        else {
            total += (n-stablec) * (minnc+1);
        }
        cout << total << endl;
    }
    return 0;
}