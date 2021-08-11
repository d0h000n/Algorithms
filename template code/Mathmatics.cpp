namespace Mathmatics {
    using ll = long long;
    template <typename T>
    struct Matrix {
        int R, C; vector<vector<T>> M, I, zero;
        Matrix(int m, int n): R(m), C(n), M(m+1,vector<T>(n+1)), I(n+1,vector<T>(n+1)), zero(m+1,vector<T>(n+1)) {
            for (int i = 1; i <= n; ++i) I[i][i] = 1;
        }
        Matrix operator * (const Matrix<T>& rhs) {
            assert(C == rhs.R);
            Matrix<T> r(R,rhs.C);
            for (int i = 1; i <= R; ++i) for (int j = 1; j <= rhs.C; ++j) {
                for (int k = 1; k <= C; ++k)
                    r.M[i][j] += M[i][k]*rhs.M[k][j];
            }
            return r;
        }
        Matrix operator * (const T& k) {
            Matrix<T> r(R,C);
            for (int i = 1; i <= R; ++i) for (int j = 1; j <= C; ++j)
                r.M[i][j] = M[i][j]*k;
            return r;
        }
        Matrix& operator *= (const T& k) {
            M = M*k;
            return *this;
        }
        Matrix operator ^ (const ll& n) {
            assert(R == C);
            Matrix<T> r(R,R), tmp(R,R);
            r.M = I, tmp.M = M;
            for (ll k = n; k >= 1; k >>= 1) {
                if (k&1) r = r*tmp;
                tmp = tmp*tmp;
            }
            return r;
        }
        Matrix operator + (const Matrix<T>& rhs) {
            Matrix<T> r(R,C);
            for (int i = 1; i <= R; ++i) for (int j = 1; j <= C; ++j) {
                r.M[i][j] = M[i][j]+rhs.M[i][j];
            }
            return r;
        }
        Matrix operator - (const Matrix<T>& rhs) {
            Matrix<T> r(R,C);
            for (int i = 1; i <= R; ++i) for (int j = 1; j <= C; ++j) {
                r.M[i][j] = M[i][j]-rhs.M[i][j];
            }
            return r;
        }
        Matrix& operator += (const Matrix<T>& rhs) {
            M = M+rhs;
            return *this;
        }
        Matrix& operator -= (const Matrix<T>& rhs) {
            M = M-rhs;
            return *this;
        }
    };
    namespace ModularArithmetic {
        bool done = false;
        void precalc() {
            if (done) return;
            done = true;
        }
        template <ll P>
        struct Int_Mod_P {
            int x;
        };
        struct Int_Mod_M {
            ;
        };
    }
    struct Sieve {
        int B; //boundary
        vector<int> lpf, prime, totient; // number of multiples
        vector<short> mobius;
        Sieve(int b): B(b), lpf(b+1), totient(b+1), mobius(b+1) { // O(B)
            lpf[0] = lpf[1] = -1, mobius[1] = totient[1] = 1;
            for (int x = 2; x <= B; ++x) {
                if (!lpf[x]) prime.push_back(x), mobius[x] = -1, totient[1] = 1;
                for (auto p : prime) {
                    if (x*p > B) break;
                    lpf[x*p] = p;
                    if (x%p == 0) {
                        mobius[x*p] = 0, totient[x*p] = totient[x]*p;
                        break;
                    }
                    mobius[x*p] = mobius[x]*mobius[p];
                    totient[x*p] = totient[x]*totient[p];
        }}}
        bool is_prime(ll n) {
            // O(1) when n<=B, O(n/log(n)) when B<n<=B², O(√n) when n>B²
            if (n <= B) return lpf[n] == n;
            if (n <= B*B) {
                for (int p : prime) if (n%p == 0) return false;
                return true;
            }
            for (ll p = 2; p*p <= n; ++p) if (n%p == 0) return false;
            return true;
        }
        short mobius_large(ll n) {
            // O(1) when n<=B, O(n/log(n)) when B<n<=B², O(√n) when n>B²
            if (n <= B) return mobius[n];
            int res = 1;
            if (n <= B*B) {
                for (int p : prime) {
                    if (n%p == 0) {
                        if (n/p%p == 0) return 0;
                        n /= p, res = -res;
                }}
                if (n > 1) return -res;
                return res;
            }
            for (ll p = 2; p*p <= n; ++p) {
                if (n%p == 0) {
                    if (n/p%p == 0) return 0;
                    n /= p, res = -res; //제곱인수 있으면 이미 걸러져서 1번만 나눠도 충분
            }}
            if (n > 1) return -res;
            return res;
        }
        ll totient_large(ll n) {
            // O(1) when n<=B, O(n/log(n)) when B<n<=B², O(√n) when n>B²
            if (n <= B) return totient[n];
            ll res = n;
            if (n <= B*B) {
                for (int p : prime) {
                    if (n%p == 0) {
                        while (n%p == 0) n /= p;
                        res -= res/p;
                }}
                if (n > 1) return res-res/n;
                return res;
            }
            for (ll p = 2; p*p <= n; ++p) {
                if (n%p == 0) {
                    while (n%p == 0) n /= p;
                    res -= res/p;
            }}
            if (n > 1) return res-res/n;
            return res;
        }
        vector<ll> factors_large(ll n) {
            // O(log n) when n<=B, O(n/log(n)) when B<n<=B², O(√n) when n>B²
            vector<ll> f;
            if (n <= B) {
                while (lpf[n] > 0) f.push_back(lpf[n]), n /= lpf[n];
                return f;
            }
            if (n <= B*B) {
                for (int p : prime)
                    while (n%p == 0) f.push_back(p), n /= p;
                if (n > 1) f.push_back(n);
                return f;
            }
            for (ll p = 2; p*p <= n; ++p)
                while (n%p == 0) f.push_back(p), n /= p;
            if (n > 1) f.push_back(n);
            return f;
        }
    };
}
