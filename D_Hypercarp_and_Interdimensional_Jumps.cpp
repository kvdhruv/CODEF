#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

// // ok, if we maek n moves, mag wise, we move n * (n + 1) / 2 // as first move 1, second 2 ..
// so 
// if x + y == n * ( n + 1 ) / 2 for some n, we can always reach. 
// else greedy ? not sure. 

// we will find max n as it should be in bounds. 
// so we can reach reach till the line x + y == that max n calculated. aha. then min dist from destination to the line gives the target.
// n( n + 1 ) <= 2(sum)
// n^2 + n - 2(sum) <= 0. 
// n <= -1 + root(1 + 8(sum)) / 2
// xx + yy = maxn. dist from x,y ->  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll x, y; cin >> x >> y;
        ll maxn = 1;
        for (ll i = 1; i * (i + 1) / 2 <= x + y; i++) {
            maxn = i;
        }

        ll steps = maxn * (maxn + 1) / 2;
        // minimize -> (xx - x) ^ 2 + (yy - y) ^ 2. xx + yy = steps.
        // xx = (x - y + steps) / 2;
        ll xx = (x - y + steps) / 2;
        ll xx1 = xx + 1;
        
        if (xx < 0) xx = 0;
        if (xx > steps) xx = steps;
        if (xx1 < 0) xx1 = 0;
        if (xx1 > steps) xx1 = steps;
        
        ll dist1 = (xx - x) * (xx - x) + (steps - xx - y) * (steps - xx - y);
        ll dist2 = (xx1 - x) * (xx1 - x) + (steps - xx1 - y) * (steps - xx1 - y);
        ll target;
        if (dist1 <= dist2) {
            target = xx;
        } else {
            target = xx1;
        }

        string ans(maxn, 'Y');
        for (ll i = maxn; i >= 1; i--) {
            if (target >= i) {
                target -= i;
                ans[maxn - i] = 'X'; 
            }
        }
        
        cout << ans << "\n";

    }

    return 0;
}