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
const int MAXN = 100005;
const int bits = 30; 

vector<pair<int, int>> graph[MAXN];
vector<bool> vis(MAXN, false);
int dist[MAXN];
int basis[bits];

void add_basis(int mask) {
    for (int i = bits - 1; i >= 0; i--) {
        if ((mask >> i) & 1) {
            if (!basis[i]) {
                basis[i] = mask;
                return;
            }
            mask ^= basis[i];
        }
    }
}

void dfs(int u, int curr_xor) {
    vis[u] = true;
    dist[u] = curr_xor;
    for (const auto& edge : graph[u]) {
        int v = edge.first;
        int w = edge.second;

        if (!vis[v]) {
            dfs(v, curr_xor ^ w);
        } else {
            int cycle_xor = curr_xor ^ dist[v] ^ w;
            add_basis(cycle_xor);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dfs(1, 0);
    int ans = dist[n];

    for (int i = bits - 1; i >= 0; i--) {
        if ((ans ^ basis[i]) < ans) {
            ans ^= basis[i];
        }
    }

    cout << ans << "\n";

    return 0;
}