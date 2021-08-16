template <typename T>
T pow(T x, const ll& n, const T& id) {
    T r = id;
    for (ll k = n; k >= 1; k >>= 1, x = x*x) if (k&1) r = r*x;
    return r;
}
