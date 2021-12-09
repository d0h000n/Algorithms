template <typename T> using Operation = function<T(const T&,const T&)>;

template <typename T, const int N>
struct SegmentTree {
    vector<T> t; Operation<T> op;
    SegmentTree(T e, Operation<T> f): t((N+2)<<2,e), op(f) {}
    void update(int p, T x, int k = 1, int s = 0, int e = N) {
        if (p <= s and e <= p) {t[k] = x; return;}
        if (p < s or e < p) return;
        update(p,x,2*k,s,(s+e)/2), update(p,x,2*k+1,(s+e)/2+1,e);
        t[k] = op(t[2*k],t[2*k+1]);
    }
    T query(int a, int b, int k = 1, int s = 0, int e = N) {
        if (a <= s and e <= b) return t[k];
        if (b < s or e < a) return t[0];
        return op(query(a,b,2*k,s,(s+e)/2),query(a,b,2*k+1,(s+e)/2+1,e));
    }
};
