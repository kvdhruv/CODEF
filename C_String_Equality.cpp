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
        int n, k; cin >> n >> k;
        string a, b; cin >> a >> b;
        vector<int> fa(26), fb(26);

        for (int i = 0; i < n; i++) {
            fa[a[i] - 'a']++;
            fb[b[i] - 'a']++;
        }

        bool poss = true;
        for (int i = 0; i < 26; i++) {
            if (fa[i] < fb[i] || (fa[i] - fb[i]) % k != 0) {
                poss = false;
                break;
            }
            if (i < 25) {
                fa[i + 1] += (fa[i] - fb[i]);
            }
        }
        if (poss)  {
            yes;
        } else {
            no;
        }
    }

    return 0;
}