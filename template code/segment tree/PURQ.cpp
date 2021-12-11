template <typename T> using Operation = function<T(const T&, const T&)>;

template <typename T, const int n>
struct RUPQ {
  T t[2*n]; Operation<T> op; T *array = t+n;
  RUPQ(T e, Operation<T>): op(f) {fill(t,t+2*n,e);}
  void build() {
    for (int k = n-1; k; --k)
      t[k] = op(t[2*k],t[2*k+1]);
  }
  void update(int k, T v) {
    for (t[k += n] = v; k > 1; k /= 2)
      t[k/2] = op(t[k],t[k^1]);
  }
  T query(int a, int b) {
    T l = t[0], r = t[0];
    for (a += n, b += n; a <= b; a /= 2, b /= 2) {
      if (a&1) l = op(l,t[0]);
      if (~b&1) r = op(t[0],r);
    }
    return op(l,r);
  }
};
