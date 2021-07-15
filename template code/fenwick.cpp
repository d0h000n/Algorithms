template <typename T>
struct Fenwick {
    T tree[N];
    T sum(int k) {T s = 0; while (k) s += tree[k], k -= k&-k; return s;}
    void update(int k, T x) {while (k < N) tree[k] += x, k += k&-k;}
};
