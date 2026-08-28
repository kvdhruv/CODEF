#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

const int MOD = 998244353;
const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> degree(n + 1);
    vector<int> leaf_conn(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++; degree[b]++;
    }

    bool even = false, odd = false;
    function<void(int, int, int)> dfs = [&](int node, int par, int d) -> void {
        bool leaf = true;
        for (const auto child : g[node]) {
            if (par != child) {
                leaf = false;
                dfs(child, node, d + 1);
            }
        }
        if (leaf) {
            even |= (d % 2 == 0);
            odd |=  (d % 2 == 1);
            // cout << even << ' ' << odd << endl;
        }
    };

    for (int i = 1; i <= n; i++) {
        if (degree[i] > 1) {
            dfs(i, -1, 0); 
            break;
        }
    }

    int mini = 1;
    if (even && odd) {
        mini = 3;
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            leaf_conn[g[i][0]]++;
        }
    }

    int maxi = n - 1;
    for (int i = 1; i <= n; i++) {
        if (leaf_conn[i] > 0) {
            maxi -= (leaf_conn[i] - 1);
        }
        // cout << leaf_conn[i] << ' ';
    }

    cout << mini << ' ' << maxi << endl;

    return 0;
}