using namespace std;
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
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

bool ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    string res;
    cin >> res;
    return res == "YES";
}

void sort_sub(vector<int> &nums, vector<int> &search, int l, int r) {
    if (search.size() == 0)
        return;
    if (r- l== 0) {
        nums[search[0] - 1] = l + 1;
        // cout << "end add " << nums[search[0]-1] << " at " << search[0] - 1 << endl;
        return;
    }
    for (int i = 0; i < rand() % 10; i++) {
        rand();
    }
    int crand = rand();
    int pivot = (crand % (r- l));
    // cout << crand << endl;
    // cout << pivot << endl;
    vector<int> left, right;
    for (int i = 0; i <= r - l; i++) {
        if (i == pivot)
            continue;
        if (ask(search[i], search[pivot])) {
            // so i less than pivot
            left.push_back(search[i]);
        }
        else {
            right.push_back(search[i]);
        }
    }
    nums[search[pivot]-1] = l + left.size() + 1;
    // cout << "pivot add " << nums[search[pivot]-1] << " at " << search[pivot] - 1 << endl;
    sort_sub(nums, left, l, l+left.size()-1);
    sort_sub(nums, right, l + left.size() + 1, r);
}

vector<int> merge_sort(int l, int r) {
    if (r - l == 0) {
        vector<int> ret(1);
        ret[0] = l + 1;
        return ret;
    }
    int mid = (l + r) / 2;
    vi left = merge_sort(l, mid);
    vi right = merge_sort(mid+1, r);
    vi ret(r - l + 1);
    int lp = 0, rp = 0;
    for (int i = 0; i < r - l + 1; i++) {
        if (lp == left.size()) {
            ret[i] = right[rp];
            rp++;
            continue;
        }
        if (rp == right.size()) {
            ret[i] = left[lp];
            lp++;
            continue;
        }
        if (ask(left[lp], right[rp])) {
            // left is smaller
            ret[i] = left[lp];
            lp++;
        }
        else {
            ret[i] = right[rp];
            rp++;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("test.in");
    int n;
    cin >> n;
    if (n == 1) {
        cout << "! 1" <<endl;
        return 0;
    }
    vi ret(n), nums(n);
    // quick sort
    // sort_sub(nums, ret, 0, n-1);
    nums = merge_sort(0, n-1);
    // cout << "? 1 2" << endl;
    // cout.flush();
    // string res;
    // cin >> res;
    // if (res == "YES") {
    //     order.push_back(1);
    //     order.push_back(2);
    // }
    // else {
    //     order.push_back(2);
    //     order.push_back(1);
    // }
    // for (int i = 3; i <= n; i++) {
    //     int op = 0;
    //     while (true) {
    //         if (op >= (int)order.size()) {
    //             order.push_back(i);
    //             break;
    //         }
    //         cout << "? " << i << " " << order[op] << endl;
    //         cout.flush();
    //         cin >> res;
    //         if (res == "YES") {
    //             // stop here
    //             order.insert(order.begin() + op, i);
    //             break;
    //         }
    //         op++;
    //     }
    // }
    for (int i = 0; i < n; i++) {
        ret[nums[i] - 1] = i + 1;
    }
    cout << "! ";
    for (int &c : ret)
        cout << c << " ";
    cout << endl;
    return 0;
}