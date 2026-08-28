#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

bool check(int mid, int n, int m, vector<vector<ll>>& g, vector<ll>& v) {
    if (mid == m) return true;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            pq.push(g[i][j]);
            sum = sum + g[i][j];
            if (pq.size() > mid) {
                sum = sum - pq.top();
                pq.pop();
            }
        }

        if (sum >= v[i]) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<vector<ll>> g(n, vector<ll>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }

        int low = 1, high = m, mid;
        int ans = m;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (check(mid, n, m, g, v)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}