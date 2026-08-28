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

ll ncr(int n, int r) {
    if (r < 0 || r > n) return 0LL;
    if (r > n / 2) r = n - r;
    
    ll num = 1, den = 1;
    for (int i = 0; i < r; i++) {
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }
    
    ll base = den, exp = MOD - 2, inv = 1;
    while (exp > 0) {
        if (exp % 2 == 1) inv = (inv * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    
    return (num * inv) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> diff;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) {
                diff.push_back(1);
            } else {
                diff.push_back(0);
            }
        }
        
        int ones = 0, even = 0, odd = 0;
        for (int i = 0; i < n - 1; i++) {
            if (diff[i] == 1) {
                ones = ones + 1;
            } else {
                if (ones % 2 == 0) {
                    even = even + 1;
                } else {
                    odd = odd + 1;
                }
            }
        }

        if (ones == 0) {
            cout << 1 << "\n";
            continue;
        }

        ll eways = ncr(even + (ones / 2), ones / 2);
        ll oways = ncr(odd + (ones - 1) / 2, (ones - 1) / 2);

        cout << (eways * oways) % MOD << "\n";
    }

    return 0;
}