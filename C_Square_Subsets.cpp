#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get(s) string s; cin>>s;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define v_sort(v) sort(v.begin(), v.end())
#define rv_sort(v) sort(v.rbegin(), v.rend())

const int BITS = 19; 
const int MOD = 1e9 + 7;
vector<int> basis(BITS);
int basis_size = 0;

ll power(ll base, ll expo) {
    ll ans = 1; base = base % MOD;
    while(expo > 0) {
        if (expo & 1) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        expo >>= 1;
    }
    return ans;
}

void add_basis(int mask) {
    for (int i = BITS - 1; i >= 0; i--) {
        if ((mask >> i) & 1) {
            if (!basis[i]) {
                basis[i] = mask;
                basis_size++;
                return;
            }
            mask ^= basis[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> primes;
    for (int i = 2; i <= 70; i++) {
        bool prime = true;
        for (int j = 2; j * j <= i; j = j + 1) {
            if (i % j == 0) {
                prime = false;
            }
        }
        if (prime) primes.push_back(i);
    }
    assert(primes.size() == 19);

    for (auto val : v) {
        int mask = 0;
        for (int i = 0; i < 19; i++) {
            int count = 0;
            while (val % primes[i] == 0) {
                count ^= 1;
                val /= primes[i];
            }
            if (count > 0) mask |= (1 << i);
        }
        add_basis(mask);
    }

    int free = n - basis_size;
    ll ans = (power(2, free) - 1 + MOD) % MOD;
    cout << ans << endl;

    return 0;
}