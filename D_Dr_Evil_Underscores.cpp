#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

int solve(vector<int> &v, int bit) {
    if (v.empty() || bit < 0) {
        return 0;
    }
    vector<int> ones, zero;
    for(const auto& val : v) {
        if ((val >> bit) & 1) {
            ones.push_back(val);
        } else {
            zero.push_back(val);
        }
    }

    if (ones.empty()) {
        return solve(zero, bit - 1);
    }
    if (zero.empty()) {
        return solve(ones, bit - 1);
    }

    int onn = solve(zero, bit - 1);
    int off = solve(ones, bit - 1);

    return (1 << bit) + min(onn, off);
}


int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << solve(v, 29) << endl;

    return 0;
}