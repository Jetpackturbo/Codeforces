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
#include <cstring>
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
typedef vector<vector<ll> > vvll;
typedef vector<string> vs;

// #define endl '\n'
// #define no cout<<"NO"<<endl
// #define yes cout<<"YES"<<endl
#define en end()
#define be begin()
#define fo(a,b,c) for(int i = a; i < b; i+=c)
#define srt(a) sort(a.be, a.en)
#define NMAX numeric_limits<ll>::max()
const ll MOD = 998244353, mod=1e9+7;
#define NMIN numeric_limits<int>::min()
#define intin(v, n) for(int i = 0; i < n; i++) cin >> v[i];
#define cout_space(v) for (int &c : v) cout << c << " "

ll string_hash(string &s) {
    ll hash = 0;
    for (int i = 0; i < s.length(); i++) {
        hash *= 26;
        hash += s[i] - 'a';
        hash %= mod;
    }
    return hash;
}

struct Node {
    int next[26];
    bool end;
    Node() { memset(next, -1, sizeof(next)); end = false; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("wordcombination.in");
    string s;
    cin >> s;
    int m, n = s.length();
    cin >> m;
    vector<Node> trie(1);
    for (int i = 0; i < m; ++i) {
        string w; 
        cin >> w;
        int cur = 0;
        for (char c : w) {
            int idx = c - 'a';
            if (trie[cur].next[idx] == -1) {
                trie[cur].next[idx] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].next[idx];
        }
        trie[cur].end = true;
    }

    vector<ll> dp(n+1, 0);
    dp[n] = 1;
    for (int i = n-1; i >= 0; --i) {
        int cur = 0;
        for (int j = i; j < n; ++j) {
            int idx = s[j] - 'a';
            if (trie[cur].next[idx] == -1) break;
            cur = trie[cur].next[idx];
            if (trie[cur].end) {
                dp[i] = (dp[i] + dp[j+1]) % MOD;
            }
        }
    }
    cout << dp[0] % MOD << "\n";
    return 0;
}