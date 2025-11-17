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
typedef vector<ll> vll;

const int LIM = 1e6;
vi eratosthenes() {
    const int S = (int)round(sqrt(LIM)), R = LIM / 2;
    vi pr, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
    pr[0] = 2;
    vector<pii> cp;
    for (int i = 3; i <= S; i+= 2) if (!sieve[i]) {
        cp.push_back(make_pair(i,i*i/2));
        for (int j=i*i; j <= S; j+= 2*i) sieve[j] = 1;
    }
    for (int L = 1; L <= R; L += S) {
        vector<bool> block(S);
        for (auto &[p, idx] : cp)
            for (int i = idx; i < S + L; idx = (i+=p)) block[i-L] = 1;
        rep(i,0,min(S,R-L))
            if(!block[i]) pr.push_back((L+i) * 2 + 1);
    }
    return pr;
}

void addupto(vi &uret, vi &bret, vi &primes, int lprim, int ci) {
    if (lprim <= 0 || ci >= bret.size())
        return;
    else if (lprim == 1) {
        uret[ci] = 1;
        bret[ci] = 1;
        return;
    }
    // identify prime larger than n
    int lp = *upper_bound(primes.begin(), primes.end(), lprim);
    // cout << lp << endl;
    for (int i = 0; i < (2 * lprim - lp + 1) / 2; i++) {
        // cout << ci << " " << lp-lprim << endl;
        uret[ci] = lp - lprim + i;
        uret[ci+1] = lprim  - i;
        bret[ci+1] = lp - lprim + i;
        bret[ci] = lprim - i;
        ci += 2; 
    }
    // cout << lprim - ci << " " << ci << endl;
    addupto(uret, bret, primes, uret.size() - ci, ci);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("test.in");
    int n;
    cin >> n;
    vi primes = eratosthenes();
    vi uret(n), bret(n);
    addupto(uret, bret, primes, n, 0);
    for (int i : uret) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : bret) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}