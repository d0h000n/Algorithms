template <typename T>
struct FenwickTree {
    T tree[N] = {0,};
    T sum(int k) {T s = 0; while (k) s += tree[k], k -= k&-k; return s;}
    void update(int k, T x) {while (k < N) tree[k] += x, k += k&-k;}
};
//펜윅트리는 구간합 빨리 구해야 할 때 빠르게 타이핑해서 활용할 수 있는 자료구조이다.
