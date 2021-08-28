template <typename T>
struct LazySegmentTree {
private:
    int N; vector<T> tree, lazy; function<T(const T&,const T&)> op;
    #define U(x,y) x = op(x,y)
    #define L k<<1
    #define R (k<<1)|1
    #define left L,s,(s+e)>>1
    #define right R,((s+e)>>1)+1,e
    void propagate(int k, int s, int e) {
        if (lazy[k] == tree[0]) return;
        U(tree[k],lazy[k]*(e-s+1));
        if (s != e) U(lazy[L],lazy[k]), U(lazy[R],lazy[k]);
        lazy[k] = tree[0];
    }
    void update(int a, int b, T x, int k, int s, int e) {
        if (a <= s and e <= b) {U(lazy[k],x), propagate(k,s,e); return;}
        propagate(k,s,e);
        if (b < s or e < a) return;
        update(a,b,x,left), update(a,b,x,right);
        tree[k] = op(tree[L],tree[R]);
    }
    T query(int a, int b, int k, int s, int e) {
        propagate(k,s,e);
        if (a <= s and e <= b) return tree[k];
        if (b < s or e < a) return tree[0];
        return op(query(a,b,left),query(a,b,right));
    }
    #undef U
    #undef L
    #undef R
    #undef left
    #undef right
public:
    LazySegmentTree(int n, T id, function<T(const T&,const T&)> f):
        N(n), tree((n+1)<<2,id), lazy((n+1)<<2,id), op(f) {}
    void update(int a, int b, T x) {update(a,b,x,1,1,N);}
    T query(int a, int b) {return query(a,b,1,1,N);}
};
