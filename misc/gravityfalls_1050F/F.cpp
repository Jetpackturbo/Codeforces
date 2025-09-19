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

const int MOD = 1000000007;

int main(){
    ifstream cin("F.in");
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<vector<int>> nums(n);
        int mk = -1;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            mk = max(k, mk);
            vector<int> cv(k);
            for(int i = 0; i < k; i++) {
                cin >> cv[i];
            }
            nums[i] = cv;
        }
        int pk = 0;
        while (pk < mk) {
            int bi = 0, bf = 1e6;
            for (int i = 0; i < n; i++) {
                if(nums[i].size() > pk && nums[i][pk] < bf) {
                    bi = i;
                    bf = nums[i][pk];
                }
                else if (nums[i].size() > pk && nums[i][pk] == bf) {
                    // break tie:
                    bool swap = false;
                    for (int j = pk; j < min(nums[bi].size(), nums[i].size()); j++) {
                        if (nums[bi][j] > nums[i][j]){
                            swap = true;
                            break;
                        }
                        else if (nums[bi][j] == nums[i][j]) {
                            if(j == min(nums[bi].size(), nums[i].size()) - 1 && nums[i].size() < nums[bi].size()) {
                                bi = i;
                            }
                        }
                        else {
                            break;
                        }
                    }
                    if (swap){
                        bi = i;
                    }
                }
            }
            for (int i = pk; i < nums[bi].size(); i++) {
                cout << nums[bi][i] << " ";
            }
            pk = nums[bi].size();
        }
        cout << endl;
    }
    return 0;
}