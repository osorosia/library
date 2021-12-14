#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

template <class T, class U>
class StaticRangeSum {
public:
    vector<T> imos;
    StaticRangeSum(U N, vector<T> A) : imos(N + 1) {
        for (int i = 0; i < N; i++) {
            imos[i + 1] += imos[i] + A[i];
        }
    }

    T sum(U l, U r) {
        return imos[r] - imos[l];
    }
};

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    StaticRangeSum srs(N, a);

    rep(q, Q) {
        ll l, r;
        cin >> l >> r;
        cout << srs.sum(l, r) << endl;
    }
}