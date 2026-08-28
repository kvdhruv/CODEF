#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sum;
    int min_pref;
    int max_pref;
};

const int MAXN = 200005;
const int INF = 1e9; // Identity constant for min/max
Node tree[4 * MAXN];
int arr[MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = {arr[start], arr[start], arr[start]};
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    tree[node].min_pref = min(tree[2 * node].min_pref, tree[2 * node].sum + tree[2 * node + 1].min_pref);
    tree[node].max_pref = max(tree[2 * node].max_pref, tree[2 * node].sum + tree[2 * node + 1].max_pref);
}

Node query(int node, int start, int end, int l, int r) {
    // Return identity element for out-of-bounds ranges
    if (r < start || end < l) {
        return {0, INF, -INF};
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    Node left_res = query(2 * node, start, mid, l, r);
    Node right_res = query(2 * node + 1, mid + 1, end, l, r);
    
    Node res;
    res.sum = left_res.sum + right_res.sum;
    res.min_pref = min(left_res.min_pref, left_res.sum + right_res.min_pref);
    res.max_pref = max(left_res.max_pref, left_res.sum + right_res.max_pref);
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == t[i-1]) {
            arr[i] = 0;
        } else if (s[i-1] == '0' && t[i-1] == '1') {
            arr[i] = 1;
        } else {
            arr[i] = -1;
        }
    }
    
    build(1, 1, n);
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        Node res = query(1, 1, n, l, r);
        if (res.sum == 0 && res.min_pref >= 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}