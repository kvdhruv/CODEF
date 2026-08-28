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

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); 
    }
    bool unite(int i, int j) {
        int pi = find(i);
        int pj = find(j);
        if (pi != pj) {
            parent[pi] = pj;
            return true;
        }
        return false;
    }
};

struct edge {
    ll u, v, w;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<ll, ll>> coords(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }

    vector<ll> c(n + 1), k(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    vector<edge> edges;
    for (int i = 1; i <= n; i++) {
        edges.push_back({0, i, c[i]});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ll dist = abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second);
            ll cost = dist * (k[i] + k[j]);
            edges.push_back({i, j, cost});
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    ll total_cost = 0;
    vector<int> stations;
    vector<pair<int, int>> wires;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            total_cost += edge.w;
            if (edge.u == 0 || edge.v == 0) {
                stations.push_back(max(edge.u, edge.v)); 
            } else {
                wires.push_back({edge.u, edge.v});
            }
        }
    }

    cout << total_cost << "\n";
    cout << stations.size() << "\n";
    for (const auto& s : stations) {
        cout << s << " ";
    }
    cout << "\n" << wires.size() << "\n";
    for (const auto& w : wires) {
        cout << w.first << " " << w.second << "\n";
    }

    return 0;
}