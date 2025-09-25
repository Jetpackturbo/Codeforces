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
        int n;
        cin >> n;
        vi nums(n);
        unordered_map<int, int> counts;
        fo(0,n,1) {
            cin >> nums[i];
            counts[nums[i]]++;
        }
        bool works = true;
        int cpos = 1;
        for (auto &cp : counts) {
            if (cp.second % cp.first != 0) {
                cout << -1 << endl;
                works = false;
                break;
            }
        }
        if (works) {
            unordered_map<int, int> pa;
            int cp = 1;
            fo(0, n, 1) {
                if (pa.find(nums[i]) == pa.end()) {
                    pa[nums[i]] = cp;
                    cp++;
                }
                cout << pa[nums[i]] << " ";
                counts[nums[i]]--;
                if (counts[nums[i]] % nums[i] == 0) {
                    pa[nums[i]] = cp;
                    cp++;
                }
            }
            cout << endl;
        }
    }
    return 0;
}