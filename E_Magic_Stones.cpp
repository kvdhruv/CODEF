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
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // 3 7 8 6
    // -4 -1 2
    // 3 4 8 6
    // -1 -4 2 diff swap.
    vector<ll> diffa(n - 1), diffb(n - 1);
    for (int i = 0; i < n - 1; i++) {
        diffa[i] = a[i + 1] - a[i];
        diffb[i] = b[i + 1] - b[i];
    }
    v_sort(diffa);
    v_sort(diffb);

    if (a[0] == b[0] && a[n - 1] == b[n - 1] && diffa == diffb) {
        yes;
    } else {
        no;
    }

    return 0;
}