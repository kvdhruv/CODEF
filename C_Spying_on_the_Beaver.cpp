#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> tree(n + 1);
        for (int i = 2; i <= n; i++) {
            int par; cin >> par;
            tree[par].push_back(i);
            tree[i].push_back(par);
        }

        int m; cin >> m;
        vector<int> v(m);
        set<int> water;
        for (int i = 0; i < m; i++) {
            cin >> v[i];
            water.insert(v[i]);
        }

        int last = -1;
        function<void(int, int)> dfs = [&](int node, int par) -> void {
            if (last == -1 && water.count(node)) {
                last = node;
                // cout << last;
            }
            for (const auto child : tree[node]) {
                if (child == par) continue;
                dfs(child, node);
            }
        };

        dfs(1, -1);

        cout << m - 1 << ' ';
        for (int i = 0; i < m; i++) {
            if (v[i] == last) continue;
            cout << v[i] << ' ';
        }
        cout << endl;

    }

    return 0;
}