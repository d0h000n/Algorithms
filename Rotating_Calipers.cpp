#include <bits/stdc++.h>
#define X real()
#define Y imag()
#define cross(u, v) (conj(u)*(v)).Y
#define sz(x) (int)x.size()
using namespace std;
using C = long double;
using P = complex<C>;
using poly = vector<P>;
const C TAU = 6.2831853;
#define radToDeg(x) 360*(x)/TAU

C ang(P u, P v) {
    C au = arg(u), av = arg(v);
    if (au < av) swap(au, av);
    C theta = au-av;
    if (theta >= TAU) theta -= TAU;
    return min(TAU-theta, theta);
}

bool cmp(const P& a, const P& b) {
    if (a.X == b.X) return a.Y < b.Y;
    return a.X < b.X;
}

bool shouldPop(const poly& hull, const P& p) {
    if (sz(hull) < 2) return false;
    return cross(hull.back()-*(hull.end()-2), p-hull.back()) >= 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    P p[n]; poly up, lo;
    for (auto& s: p) {
        C x, y; cin >> x >> y;
        s = {x, y};
    }
    //make convex hull
    sort(p, p+n, cmp);
    for (int i = 0; i < n; ++i) {
        while (shouldPop(up, p[i])) up.pop_back();
        while (shouldPop(lo, p[n-1-i])) lo.pop_back();
        up.push_back(p[i]); lo.push_back(p[n-1-i]);
    }
    //rotating calipers
    C ans = 0;
    P calipers = {0, 1};
    int L = sz(lo)-1, R = sz(up)-1;
    int a = 0, b = 0;
    while (a < R || b < L) {
        if (ang(calipers, up[a+1]-up[a]) > ang(-calipers, lo[b+1]-lo[b])) {
            calipers = -lo[b+1]+lo[b]; ++b;
        } else {
            calipers = up[a+1]-up[a]; ++a;
        }
        ans = max(ans, abs(up[a]-lo[b]));
    }
    cout << fixed; cout.precision(6);
    cout << ans;
}
