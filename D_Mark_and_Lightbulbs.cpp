#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

int calc(const string& s, vector<pair<int, int>>& vec) {
    int size = s.size();
    int l = 0, r = 0;
    for (int r = 0; r < size; r++) {
        if (s[l] == s[r]) continue;
        vec.push_back({l, r - 1});
        l = r;
    }
    vec.push_back({l, r - 1});
    return vec.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        vector<pair<int, int>> vs, vt;
        if (calc(s, vs) != calc(t, vt)) {
            cout << "-1\n";
        } else {
            if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
                cout << "-1\n";
            } else {
                ll ans = 0; int size = vs.size();
                for (int i = 0; i < size; i++) {
                    ans = ans + abs(vs[i].second - vt[i].second);
                }
                cout << ans << endl;
            }
        }
    }

    return 0;
}