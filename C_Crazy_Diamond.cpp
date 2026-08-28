#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

void myswap(int a, int b, vector<int>& index, vector<int>& vec, vector<pair<int, int>>& ans) {
    if (a == b) return;
    ans.push_back({a, b});
    swap(vec[a - 1], vec[b - 1]);
    index[vec[a - 1]] = a;
    index[vec[b - 1]] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;    
    vector<int> v(n);
    vector<int> index(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        index[v[i]] = i + 1; 
    }

    vector<pair<int, int>> ans;
    
    for (int i = 1; i <= n; i++) {
        int ind = index[i];
        if (ind == i) continue; 

        if (abs(i - ind) >= n / 2) {
            myswap(i, ind, index, v, ans);
        } else {
            if (ind <= n / 2 && i <= n / 2) {
                myswap(ind, n, index, v, ans);
                myswap(i, n, index, v, ans);
                // myswap(ind, n, index, v, ans); 
            } else {
                if (i > n / 2 && ind > n / 2) {
                    myswap(ind, 1, index, v, ans); 
                    myswap(i, 1, index, v, ans);
                    myswap(ind, 1, index, v, ans); // missed.
                } else {

                    if (i <= n / 2) {
                        myswap(ind, 1, index, v, ans); 
                        myswap(i, n, index, v, ans);
                        myswap(1, n, index, v, ans);
                        myswap(ind, 1, index, v, ans); 
                        myswap(i, n, index, v, ans);  
                    } else {
                        assert(false);
                    }
                }  
            }  
        }
    }

    cout << ans.size() << "\n";
    for (auto [a, b] : ans) {
        cout << a << " " << b << "\n";
    }

    return 0;
}