template <typename T> class SegmentTree {
private:
    int n;
    T identity;
    vector<T> tree;
public:
    SegmentTree(T* s, T* e, T id) {
        identity = id;
        n = pow(2, ceil(log2(e-s)));
        tree.assign(2*n, identity);
        for (auto it = s; it != e; ++it) tree[it-s+n] = *it;
        for (int i = n-1; i > 0; --i) tree[i] = tree[2*i]+tree[2*i+1];
    }
    T query(int a, int b) {
        a += n; b += n; T q = identity;
        while (a <= b) {
            if (a%2 == 1) q += tree[a++]; a /= 2;
            if (b%2 == 0) q += tree[b--]; b /= 2;
        }
        return q;
    }
    void update(int k, T x) {
        tree[k+n] = x;
        for (int i = (k+n)/2; i >= 1; i /= 2)
             tree[i] = tree[2*i]+tree[2*i+1];
    }
};
