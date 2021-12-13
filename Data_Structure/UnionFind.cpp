#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)

template <class T>
class UnionFind {
public:
    vector<T> parent;
    vector<T> size;
    UnionFind(T n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    T find(T x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool same(T x, T y) {
        return find(x) == find(y);
    }

    void merge(T x, T y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
};

int main() {
    ll N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    rep(q, Q) {
        ll t, u, v;
        cin >> t >> u >> v;
        
        if (t == 0) {
            uf.merge(u, v);
        }

        if (t == 1) {
            cout << uf.same(u, v) << endl;
        }
    }
}