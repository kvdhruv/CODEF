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
        vector<ll> v(2 * n), l(n + 1, -1), r(n + 1, -1);

        for (int i = 0; i < 2 * n; i++) {
            cin >> v[i];
            if (l[v[i]] == -1) l[v[i]] = i;
            r[v[i]] = i;
        }

        vector<array<ll, 3>> seg;

        for (int i = 1; i <= n; i++) {
            ll len = r[i] - l[i] + 1;
            seg.push_back({l[i], r[i], len * (len - 1)});
        }

        sort(seg.begin(), seg.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<ll> dp(n), ends;

        for (const auto &x : seg) ends.push_back(x[1]);

        for (int i = 0; i < n; i++) {
            ll take = seg[i][2];
            int j = lower_bound(ends.begin(), ends.end(), seg[i][0]) - ends.begin() - 1;
            if (j >= 0) take += dp[j];

            ll skip = (i ? dp[i - 1] : 0);
            dp[i] = max(take, skip);
        }

        cout << 2LL * n + dp.back() << '\n';
    }

    return 0;
}