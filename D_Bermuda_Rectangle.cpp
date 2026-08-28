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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        ll sum; cin >> sum;
        ll q; cin >> q;
        vector<pair<ll, ll>> vec(q);
        for (int i = 0; i < q; i++) {
            cin >> vec[i].first >> vec[i].second;
        }

        vector<ll> facs;
        for (ll i = 1; i * i <= sum; i = i + 1) {
            if (sum % i == 0) {
                facs.push_back(i);
                if (i * i != sum) {
                    facs.push_back(sum / i);
                }
            }
        }

        // assert(facs.size() <= 7000);
        sort(facs.begin(), facs.end());

        vector<ll> pref(facs.size());

        for (int i = 0; i < facs.size(); i++) {
            ll xdis = facs[i];
            if (i > 0) xdis -= facs[i - 1];
            ll ydis = sum / facs[i];
            pref[i] = xdis * ydis;
            if (i > 0) pref[i] += pref[i - 1];
        }

        for (auto [x, y] : vec) {
            ll px = upper_bound(facs.begin(), facs.end(), x) - facs.begin() - 1;
            ll py = upper_bound(facs.begin(), facs.end(), sum / y) - facs.begin() - 1;

            ll m = min(px, py);

            ll count = facs[m] * y;
            count += pref[px] - pref[m];

            if (px + 1 < facs.size() && x > facs[px]) {
                ll h = sum / facs[px + 1];
                count += (x - facs[px]) * min(y, h);
            }
            cout << count << '\n';
        }

        // for (auto [x, y] : vec) {
        //     int count = 0;
        //     int last = 0;
        //     for (auto fac : facs) {
        //         ll h = sum / fac;
        //         if (fac <= x) {
        //             count = count + (fac - last) * min(h, y);
        //             last = fac;
        //         } else {
        //             count = count + (x - last) * min(h, y);
        //             last = x;
        //         }
        //     }
        //     cout << count << endl;
        // }

    }

    return 0;
}