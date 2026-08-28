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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> va(n), vb(n);
        ll xa = 0, xb = 0;
        for (int i = 0; i < n; i++) {
            cin >> va[i];
            xa ^= va[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> vb[i];
            xb ^= vb[i];
        }

        v_sort(va);
        v_sort(vb);

        if (va == vb) {
            yes;
            continue;
        }

        ll target = xa ^ xb;

        bool poss = false;

        for (int i = 0; i < n; i++) {
            if (va[i] == target) {
                poss = true;
                break;
            }
        }

        if (poss) {
            bool done = false;
            for (int i = 0; i < n; i++) {
                if (!done && va[i] == target) {
                    // va[i] ^= target;
                    done = true;
                } else {
                    va[i] ^= target;
                }
            }
            v_sort(va);
            if (va == vb) {
                yes;   
            } else {
                no;
            }
        } else {
            no;
        }
    }

    return 0;
}