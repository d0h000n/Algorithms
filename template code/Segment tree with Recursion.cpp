#define query(a,b) sum(a,b,1,0,n-1)

int sum(int a, int b, int k, int x, int y) {
    if (b < x || a > y) return 0;
    if (a <= x && y <= b) return tree[k];
    int d = (x+y)>>1;
    return sum(a,b,2*k,x,d) + sum(a,b,2*k+1,d+1,y);
}
