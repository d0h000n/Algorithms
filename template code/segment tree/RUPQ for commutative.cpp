template <typename T> using Operation = function<T(const T&, const T&)>;

template <typename T, const int n>
struct RUPQ {
  T t[2*n]; Operation<T> op; t *array = t+n;
  RUPQ(T e, Opeation<T> f): op(f) {fill(t,t+2*n,e);}
  void push() {
    for (int k = 1; k < n; ++k) {
      t[2*k] = op(t[2*k],t[k]);
      t[2*k+1] = op(t[2*k+1],t[k]);
      t[k] = t[0];
    }
  }
  void update(int a, int b, T v) {
    for (a += n, b += n, a <= b; ++a /= 2, --b /= 2) {
      if (a&1) t[a] = op(t[a],v);
      if (~b&1) t[b] = op(t[b],v);
    }
  }
  T query(int k) {
    T s = t[0];
    for (k += n; k; k /= 2)
      s = op(s,t[k]);
    return s;
  }
};
