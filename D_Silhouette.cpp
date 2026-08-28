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
        map<ll, ll> mp;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mp[v[i]]++;
        }
        // vector<ll> copy = v;
        // v_sort(copy);
        vector<pair<ll, ll>> copy;
        map<ll, ll> val;
        for (const auto& [key, value] : mp) {
            copy.push_back({key, value});
        }

        int size = copy.size();

        bool poss = true;
        if (copy[0].first != 0) {
            poss = false;
        }

        ll prev = 0; 
        for (int i = 1; i < size; i++) {
            ll diff = copy[i].first - copy[i - 1].first;
            if (diff % copy[i - 1].second != 0) {
                poss = false;
                break;
            }
            ll curr = diff / copy[i - 1].second;
            if (curr <= prev) {
                poss = false;
                break;
            }
            val[copy[i - 1].first] = curr;
            prev = curr;
        }

        if (poss) {
            val[copy.back().first] = prev + 1;
        } else {
            cout << "-1\n";
            continue;
        }

        // vector<ll> ans;
        for (int i = 0; i < n; i++) {
            cout << val[v[i]] << " ";
        }
        cout << endl;

    }

    return 0;
}