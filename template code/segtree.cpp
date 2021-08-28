template <typename T>
struct SegmentTree {
private:
    int N; vector<T> tree; function<T(const T&,const T&)> op;
    #define L k<<1
    #define R (k<<1)|1
    #define left L,s,(s+e)>>1
    #define right R,((s+e)>>1)+1,e
    void update(int t, T x, int k, int s, int e) {
        if (t <= s and e <= t) {tree[k] = x; return;}
        if (t < s or e < t) return;
        update(t,x,left), update(t,x,right);
        tree[k] = op(tree[L],tree[R]);
    }
    T query(int a, int b, int k, int s, int e) {
        if (a <= s and e <= b) return tree[k];
        if (b < s or e < a) return tree[0];
        return op(query(a,b,left),query(a,b,right));
    }
    #undef L
    #undef R
    #undef left
    #undef right
public:
    SegmentTree(int n, T id, function<T(const T&,const T&)> f):
        N(n), tree((n+1)<<2,id), op(f) {}
    void update(int t, T x) {update(t,x,1,1,N);}
    T query(int a, int b) {return query(a,b,1,1,N);}
};
