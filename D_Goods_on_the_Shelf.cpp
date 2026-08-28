#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

struct info { 
    ll count;
    ll start;
    ll end;
};

bool is_good(const vector<ll>& vec, ll total_unique) {
    ll blocks = 1;
    ll size = vec.size();
    for (ll k = 1; k < size; k++) {
        if (vec[k] != vec[k - 1]) {
            blocks++;
        }
    }
    return blocks == total_unique;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n);
        map<ll, info> mp; 

        for(ll i = 0; i < n; i++) {
            cin >> v[i];
            auto &curr = mp[v[i]];
            curr.count++;
            if (curr.count == 1) {
                curr.start = curr.end = i;
            } else {
                curr.end = i;
            }
        }

        ll bad = 0;
        vector<ll> baddies;

        for(const auto& [val, infor]: mp) {
            ll left = infor.start;
            ll right = infor.end;
            ll freq = infor.count;
            if (right - left + 1 > freq) {
                bad++;
                baddies.push_back(val);
            }
        }

        if (bad > 2) {
            no;
            continue;
        }

        if (bad == 0) {
            yes;
            continue;
        }

        vector<ll> inds;
        inds.reserve(20);

        for(const auto& val : baddies) {
            ll left = mp[val].start;
            ll right = mp[val].end;
            inds.push_back(left);
            inds.push_back(right);
            
            if (left - 1 >= 0) {
                inds.push_back(left - 1);
            }
            if (right + 1 < n)  {
                inds.push_back(right + 1);
            }
            
            for(ll i = left; i <= right; i++) {
                if (v[i] != val) {
                    inds.push_back(i);
                    inds.push_back(i - 1);
                    break;                
                }
            }
            
            for(ll i = right; i >= left; i--) {
                if (v[i] != val) {
                    inds.push_back(i);
                    inds.push_back(i + 1);
                    break;            
                }
            }
        }

        v_sort(inds);
        inds.erase(unique(inds.begin(), inds.end()), inds.end());
        assert(inds.size() <= 16);
        ll size = (ll) inds.size();
        bool poss = false;

        for(ll i = 0; i < size; i++) {
            for(ll j = i + 1; j < size; j++) {
                swap(v[inds[i]], v[inds[j]]);
                if (is_good(v, mp.size())) {
                    poss = true; break;
                }
                swap(v[inds[i]], v[inds[j]]);
            }
        }

        if (poss) {
            yes;
        } else {
            no;
        }

    }

    return 0;
}