#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

class PredecessorProblem {
public:
    set<ll> st;

    void insert(ll k) {
        st.insert(k);
    }

    void erase(ll k) {
        st.erase(k);
    }

    bool contain(ll k) {
        return st.find(k) != st.end();
    }

    ll find_next(ll k) {
        auto it = st.lower_bound(k);
        if (it == st.end())
            return -1;
        return *it;
    }

    ll find_prev(ll k) {
        auto it = st.upper_bound(k);
        if (it == st.begin())
            return -1;
        return *(--it);
    }    
};

int main() {
    ll N, Q;
    string T;
    cin >> N >> Q >> T;
    
    PredecessorProblem pp;
    rep(i, N) {
        if (T[i] == '1') pp.insert(i);
    }

    rep(qq, Q) {
        ll c, k;
        cin >> c >> k;
        if (c == 0) pp.insert(k);
        if (c == 1) pp.erase(k);
        if (c == 2) cout << pp.contain(k) << endl;
        if (c == 3) cout << pp.find_next(k) << endl;
        if (c == 4) cout << pp.find_prev(k) << endl;
    }
}
