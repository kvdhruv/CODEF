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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        // map<pair<int, int>, int>> mp;
        vector<pair<int, int>> veca, vecb;
        for (int i = 0; i < n / 2; i++) {
            veca.push_back({max(a[i], a[n - 1 - i]), min(a[i], a[n - 1 - i])}); 
            vecb.push_back({max(b[i], b[n - 1 - i]), min(b[i], b[n - 1 - i])}); 
        }

        v_sort(veca);
        v_sort(vecb);

        if (veca == vecb) {
            if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
                no;
            } else {
                yes;
            }
        } else {
            no;
        }

    }

    return 0;
}