namespace multi_sieve {
    const ll B = o_o;
    vector<int> prime;
    int lpf[B], mu[B], phi[B];
    void precalc() { // O(B)
        lpf[0] = lpf[1] = -1;
        mu[1] = phi[1] = 1;
        REP(x,2,B) {
            if (!lpf[x]) prime.push_back(x), mu[x] = -1, phi[x] = x-1;
            for (auto p : prime) {
                if (x*p > B) break;
                lpf[x*p] = p;
                if (x%p == 0) {
                    mu[x*p] = 0, phi[x*p] = phi[x]*p;
                    break;
                }
                mu[x*p] = mu[x]*mu[p];
                phi[x*p] = phi[x]*phi[p];
            }
        }
    }
    bool is_prime(ll n) {
        if (n <= B) return lpf[n] == n;
        for (ll p = 2; p*p <= n; ++p)
            if (n%p == 0) return false;
        return true;
    }
    int mobius(ll n) {
        if (n <= B) return mu[n];
        int res = 1;
        for (ll p = 2; p*p <= n; ++p) {
            if (n%p == 0) {
                if (n/p%p == 0) return 0;
                n /= p, res = -res; //제곱인수 있으면 이미 걸러져서 1번만 나눠도 충분
            }
        }
        if (n > 1) return -res;
        return res;
    }
    ll totient(ll n) {
        if (n <= B) return phi[n];
        ll res = n;
        for (ll p = 2; p*p <= n; ++p) {
            if (n%p == 0) {
                while (n%p == 0) n /= p;
                res -= res/p;
            }
        }
        if (n > 1) return res-res/n;
        return res;
    }
    vector<ll> factors(ll n) {
        vector<ll> f;
        if (n <= B) {
            while (lpf[n] > 0) f.push_back(lpf[n]), n /= lpf[n];
            return f;
        }
        for (ll p = 2; p*p <= n; ++p)
            while (n%p == 0) f.push_back(p), n /= p;
        if (n > 1) f.push_back(n);
        return f;
    }
}
    multi_sieve::precalc();
