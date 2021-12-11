template <typename T> using Operation = function<T(const T&, const T&)>;

template <typename T, const int n>
struct RUPQ {
  T t[2*n]; Operation<T> op;
  RUPQ(T e, Opeation<T> f): op(f) {fill(t,t+2*n,e);}
  
