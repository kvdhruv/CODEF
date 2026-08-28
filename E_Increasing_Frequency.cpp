#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

// let - we only care about turning some x -> c. => k = c - x. 
// it turns to kadanes where its 1 <-> x and -1 <-> c. in [l, r]. so num of c + max_sum from kadanes. 
// how do we compute this for every number ?? 

const int NAX = 5e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c; cin >> n >> c;
    vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == c) {
            ans = ans + 1;
        }
    }

    vector<int> last_seen(NAX);
    int count = 0;

    for (int i = 0; i < n; i++) {

    }

    cout << ans << endl;

    return 0;
}