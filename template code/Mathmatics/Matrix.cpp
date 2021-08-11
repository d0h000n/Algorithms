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
}
