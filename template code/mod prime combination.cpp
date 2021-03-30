const int N, P;
ll inv[N], fac[N], ifac[N];

#define positiveCombination(x,y) (C(x,y)+P)%P

//Can be negative number.
inline ll C(int x, int y) {return (x < y ? 0 : (((ll(fac[x])*ifac[y])%P)*ifac[x-y])%P);}

//precompute [1,n]'s inverses and factorial inverses
void precomputeCombinationInverses(int n) {
  inv[1] = 1;
  REP(i,2,n) inv[i] = ((ll)     -P/i*inv[P%i]      )%P;
  fac[0] = 1;
  REP(i,1,n) fac[i] = ((ll)     fac[i-1]*i         )%P;
  ifac[n] = 1;
  REP(i,1,n) ifac[n] = ((ll)    ifac[n]*inv[i]     )%P;
  ifac[0] = 1;
  PER(i,1,n-1) ifac[i] = (ll    (i+1)*ifac[i+1]    )%P;
}
