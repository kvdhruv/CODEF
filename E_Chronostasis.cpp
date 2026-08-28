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
        vector<ll> v(n);
        // set<ll> vals;
        map<ll, ll> mp;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mp[v[i]]++;
        }
        ll sum = accumulate(v.begin(), v.end(), 0LL);
        if (sum <= 0) {
            cout << "-1\n";
            continue;
        }

        vector<ll> ans(n); 
        bool poss = true;
        ll curr = 0; 

        for (int i = 0; i < n; i++) {
            auto it = mp.lower_bound(1 - curr);
            if (it == mp.end()) {
                poss = false;
                break;
            }
            
            ll val = it -> first;
            curr = curr + val;
            ans[i] = curr;
            mp[val]--;
            if (mp[val] == 0) {
                mp.erase(it);
            }
        }

        if (!poss) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}