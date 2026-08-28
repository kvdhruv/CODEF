#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        // map<int, int> reach;
        vector<int> passes(n);
        for(int i = 0; i < n; i++) { 
            cin >> v[i];
        }

        ll ans = 0;

        for(int i = 0; i < n; i++) {
            int need = v[i] - 1;
            // if (reach.find())
            if (passes[i] < need) {
                ans = ans + need - passes[i];
            }

            for (int step = i + 2; step <= min(n - 1, i + v[i]); step = step + 1) {
                passes[step]++;
            }

            if (passes[i] > need) {
                if (i + 1 < n) {
                    passes[i + 1] = passes[i + 1] + passes[i] - need;
                }
            }
        }

        cout << ans << endl;

    }
    return 0;
}
