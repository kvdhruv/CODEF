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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp(515, INF); dp[0] = -1;

    for (const auto& val : v) {
        for (int i = 0; i <= 512; i++) {
            if (dp[i] < val) {
                // if ((i ^ val) <= 512) {
                    dp[i ^ val] = min(dp[i ^ val], val);
                // }
            }
        }
    }
    // vector<int> vals;
    int count = 0;
    for (int i = 0; i <= 512; i++) {
        if (dp[i] < INF) {
            count = count + 1;
        }
    }
    // cout << vals.size() << endl;
    cout << count << endl;

    for (int i = 0; i <= 512; i++) {
        if (dp[i] < INF) {
            cout << i << ' ';
        }
    }
    cout << endl;

    return 0;
}