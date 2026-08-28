#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())


bool check(int k, vector<int>& v) {
    int n = v.size();
    if (k == 0) {
        return is_sorted(v.begin(), v.end());
    }
    
    int size = 2 * k;
    vector<int> copy = v;
    
    for (int i = 0; i < n; i += size) {
        int end = min(n, i + size);
        sort(copy.begin() + i, copy.begin() + end);
    }
    
    return is_sorted(copy.begin(), copy.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        if (check(0, v)) {
            cout << 0 << endl;
            continue;
        }
        
        int low = 0, high = 20;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int value = 1 << mid;
            
            if (check(value, v)) {
                ans = value;
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}