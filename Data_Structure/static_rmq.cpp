#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

class StaticRMQ {
public:
    const ll inf = 1001001001001LL;
    vector<ll> tree;
    ll n = 1;

    StaticRMQ (vector<ll> &A) {
        while (n < A.size()) n *= 2;
        tree.resize(2 * n - 1);
        for (ll i = 0; i < n; i++) {
            if (i < A.size()) tree[i + n - 1] = A[i];
            else tree[i + n - 1] = inf;
        }
        for (ll i = n - 2; i >= 0; i--) {
            ll left = 2 * i + 1;
            ll right = 2 * i + 2;
            tree[i] = min(tree[left], tree[right]);
        }
    }

    ll get_min(ll a, ll b) {return get_min_sub(a, b, 0, 0, n);}
    ll get_min_sub(ll a, ll b, ll k, ll left, ll right) {
        if (right <= a || b <= left)
            return inf;
        if (a <= left && right <= b)
            return tree[k];
        ll vl = get_min_sub(a, b, 2*k+1, left, (left+right)/2);
        ll vr = get_min_sub(a, b, 2*k+2, (left+right)/2, right);
        return min(vl, vr);
    }
};

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    StaticRMQ rmq(a);

    rep(qq, Q) {
        ll l, r;
        cin >> l >> r;
        cout << rmq.get_min(l, r) << endl;
    }
}
