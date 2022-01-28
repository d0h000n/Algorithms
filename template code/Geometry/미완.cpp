namespace Geometry {
    #define X real()
    #define Y imag()
    
    #define dot(u,v) (conj(u)*(v)).X
    #define cross(u,v) (conj(u)*(v)).Y
    #define ccw(a,b,c) cross((b)-(a),(c)-(b))
    
    constexpr ld PI = acos(-1.0L), TAU = 2*PI;
    
    template <typename P> istream &operator >> (istream &is, complex<P> &p) {P x, y; is >> x >> y; p = {x,y}; return is;}
    
    namespace Z_2D { // 정수 2차원 좌표계
        using P = complex<ll>;    
        #define norm(u) dot(u,u)
        ld abs(P u) {return sqrt(ld(norm(u)));} // 다른 abs와 중복 방지.
        ld arg(P u) {return atan2<ld,ld>(u.Y,u.X);}
        
        auto by_xy = [](P u, P v) {return u.X == v.X ? u.Y < v.Y : u.X < v.X;};
        
        struct Seg {
            P a, b;
            bool operator == (Seg l) {
                return a == l.a and b == l.b;
            }
        };
        
        struct Line {
            P a, b;
        };
    }
    
    namespace Taxi {
        using namespace Z_2D;
        ll dist(P p, P q) {return abs(p.X-q.X)+abs(p.Y-q.Y);}
        P translate(P p) {return {p.X+p.Y,p.Y-p.X};}
        // 좌표변환 후 벡터에 x좌표 y좌표 전부 넣고 max(max(x)-min(x),max(y)-min(y)) 구하면 지름 나옴
        // BOJ 1830 참고
    }
    
    namespace R_2D {
        using P = complex<ld>;
        constexpr ld EPS = 1e-9;
        
        bool operator == (P &u, P &v) {return abs(u.X-v.X) < EPS and abs(u.Y-v.Y) < EPS;}
        bool operator != (P &u, P &v) {return !(u == v);}
        
        struct Seg {
            P a, b;
        };
    }
    template <typename P, typename Poly>
    pair<Poly,Poly> convex_hull(const vector<P> &p) { // p는 정렬되어 있어야 한다.
        Poly up, lo;
        static auto push = [](Poly &h, P x) {
            for (int n = size(h); n >= 2 and ccw(h[n-2],h[n-1],x) >= 0; --n, h.pop_back());
            h.push_back(x);
        };
        for (int i = 0, n = size(p); i < n; ++i) push(up,p[i]), push(lo,p[n-i-1]);
        up.pop_back(), lo.pop_back();
        return MP(up,lo);
    }
}
