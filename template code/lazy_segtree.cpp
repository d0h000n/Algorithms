template <typename T, const int n>
struct RURQ {
    T t[4*n], l[4*n]; Operation<T> op;
    RURQ(T e, Operation<T> f): op(f) {fill(t,t+4*n,e), fill(l,l+4*n,e);}
    #define U(x,y) x = op(x,y)
    void propagate(int k, int s, int e) {
        U(t[k],l[k]*(e-s+1));
        if (s != e) U(l[2*k],l[k]), U(l[2*k+1],l[k]);
        l[k] = t[0];
    }
    void update(int a, int b, const T &v, int k = 1, int s = 0, int e = n-1) {
        if (a <= s and e <= b) {U(l[k],v), propagate(k,s,e); return;}
        propagate(k,s,e);
        if (b < s or e < a) return;
        update(a,b,v,2*k,s,(s+e)/2), update(a,b,v,2*k+1,(s+e)/2+1,e);
        t[k] = op(t[2*k],t[2*k+1]);
    }
    T query(int a, int b, int k = 1, int s = 0, int e = n-1) {
        propagate(k,s,e);
        if (a <= s and e <= b) return t[k];
        if (b < s or e < a) return t[0];
        return op(query(a,b,2*k,s,(s+e)/2),query(a,b,2*k+1,(s+e)/2+1,e));
    }
    #undef U
};
