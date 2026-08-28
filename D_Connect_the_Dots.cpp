#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

struct DSU {
    vector<int> parent;
    int compo;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        compo = n; 
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            compo--; 
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        DSU dsu(n);
        vector<vector<ll>> fuel(n + 1, vector<ll>(11, 0));
        for(int i = 0; i < m; i++) {
            ll a, d, k; cin >> a >> d >> k;
            fuel[a][d] = max(fuel[a][d], k);
        }

        for(int i = 1; i <= n; i++) {
            for(int d = 1; d <= 10; d++) {
                if (fuel[i][d] > 0 && i + d <= n) {
                    dsu.unite(i, i + d);
                    fuel[i + d][d] = max(fuel[i + d][d], fuel[i][d] - 1);
                }
            }
        }

        cout << dsu.compo << endl;

    }

    return 0;
}