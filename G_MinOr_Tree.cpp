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
    int comp;

    DSU (int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        comp = n - 1; 
    }

    int find (int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void merge (int i, int j) {
        int pari = find(i);
        int parj = find(j);

        if (pari != parj) {
            parent[pari] = parj;
            comp = comp - 1;
        }
    }
};

struct edge {
    int a, b, w;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<edge> v(m);
        
        for(int i = 0; i < m; i++) {
            cin >> v[i].a >> v[i].b >> v[i].w;
        }

        int allowed = (1 << 30) - 1;

        for(int bit = 29; bit >= 0; bit--) {
            DSU dsu(n + 1);
            int test = allowed & ~(1 << bit);

            for(const auto& edg : v) {
                if ((edg.w | test) == test) {
                    dsu.merge(edg.a, edg.b); 
                }
            }
            
            if (dsu.comp == 1) {
                allowed = test;
            }
        }

        cout << allowed << endl;
    }
    return 0;
}