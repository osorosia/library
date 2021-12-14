#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

class AssociativeArray {
public:
    map<ll, ll> mp;
    
    void set(ll k, ll v) {
        mp[k] = v;
    }

    ll get(ll k) {
        return mp[k];
    }
};

int main() {
    ll Q;
    cin >> Q;
    
    AssociativeArray aa;

    rep(qq, Q) {
        ll q, k, v;
        cin >> q >> k;
        if (q == 0) cin >> v;
        
        if (q == 0) aa.set(k, v);
        else cout << aa.get(k) << endl;
    }
}
