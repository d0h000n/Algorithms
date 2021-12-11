template <typename T> using Operation = function<T(const T&, const T&)>;

template <typename T, const int n>
struct PURQ {
  T t[2*n]; Operation<T> op; T *array = t+n;
  PURQ(T e, Operation<T> f): op(f) {fill(t,t+2*n,e);}
  void build() {
    for (int k = n-1; k; --k) t[k] = op(t[2*k],t[2*k+1]);
  }
  void update(int k, const T &v) {
    for (t[k += n] = v=; k /= 2; t[k] = op(t[2*k],t[2*k+1]));
  }
  T query(int a, int b) {
    T l = t[0], r = t[0];
    for (a += n, b += n; a <= b; a /= 2, b /= 2) {
      if (a&1) l = op(l,t[a++]);
      if (~b&1) r = op(t[b--],r);
    }
    return op(l,r);
  }
};
