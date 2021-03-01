ll inv[N], fac[N], ifac[N];

//Can be negative number.
ll C(int x, int y) {
    if (x < y) return 0;
    int tmp = (((fac[x]*ifac[y])%P)*ifac[x-y])%P;
    return tmp;
}

//precompute
void precomputing() {
  inv[1] = 1; fac[0] = 1; ifac[n] = 1; ifac[0] = 1;
  REPc(i,2,n) inv[i] = (-(P/i)*inv[P%i])%P;
  REPc(i,1,n) fac[i] = (fac[i-1]*i)%P;
  REPc(i,1,n) ifac[n] = (ifac[n]*inv[i])%P;
  hPER(i,n,1) ifac[i] = ((ll)(i+1)*ifac[i+1])%P;
}
