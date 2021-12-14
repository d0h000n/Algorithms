constexpr int ceil_log2(int x) {assert(x > 0); return 31-__builtin_clz(x)+bool(x&(x-1));}

const int logN = ceil_log2(N);
int par[N], spt[logN+1][N];
int lca(int a, int b) {
    if (lev[a] < lev[b]) swap(a,b);
    REP(k,0,logN) if ((lev[a]-lev[b])&(1<<k)) a = spt[k][a];
    if (a == b) return a;
    PER(k,0,logN) if (spt[k][a] != spt[k][b])
        a = spt[k][a], b = spt[k][b];
    return spt[0][a];
}
void precalc() {
    REP(i,1,n) spt[0][i] = par[i];
    REP(k,1,logN) REP(i,1,n) spt[k][i] = spt[k-1][ spt[k-1][i] ];
}
