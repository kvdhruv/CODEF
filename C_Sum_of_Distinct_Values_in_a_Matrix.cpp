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
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<int> a(x), b(y);
        // vector<bool> pre(n + m + 1, false);
        vector<bool> prea(n + m + 1, false), preb(n + m + 1, false);
        for (int i = 0; i < x; i++) {
            cin >> a[i];
            prea[a[i]] = true;
        }
        for (int i = 0; i < y; i++) {
            cin >> b[i];
            preb[b[i]] = true;
        }
        // rv_sort(a);
        // rv_sort(b);
        int mini = 1e9 + 5;
        ll ans = 0;
        // for (int i = 0; i < min(x, n); i++) {
        //     ans = ans + a[i];
        //     mini = min(mini, a[i]);
        // }
        // for (int i = 0; i < min(y, m); i++) {
        //     ans = ans + b[i];
        //     mini = min(mini, b[i]);
        // }

        // if (x + y >= n + m) ans = ans - mini;
        // cout << ans << endl;
        int acount = 0, bcount = 0, buffer = 0; // ?

        for (int i = n + m; i >= 1; i = i - 1) {
            if (!prea[i] && !preb[i]) continue;
            bool taken = false;
            if (prea[i] && preb[i]) {
                if (acount + bcount + buffer < n + m) {
                    buffer = buffer + 1;
                    taken = true;
                }
            } else if (prea[i]) {
                if (acount < n && acount + bcount + buffer < n + m) {
                    acount = acount + 1;
                    taken = true;
                }
            } else {
                if (bcount < m && acount + bcount + buffer < n + m) {
                    bcount = bcount + 1;
                    taken = true;
                }
            }
            if (taken) {
                ans = ans + i;
                mini = min(mini, i);
            }
        }

        if (acount + bcount + buffer == n + m) {
            ans = ans - mini;
        }
        cout << ans << endl;

    }

    return 0;
}