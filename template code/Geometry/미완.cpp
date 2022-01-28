namespace Geometry {
    constexpr ld PI = acos(-1.0L), TAU = 2*PI, EPS = 1e-9;
    namespace _2D {
        #define X real()
        #define Y imag()
        #define dot(u,v) (conj(u)*(v)).X
        #define cross(u,v) (conj(u)*(v)).Y
        #define ccw(a,b,c) cross((b)-(a),(c)-(b))
        #define norm(u) dot(u,u)
        
        template <typename C> istream &operator >> (istream &is, complex<C> &p) {C x, y; is >> x >> y; p = {x,y}; return is;}
        
        namespace Z { // 정수 2차원 좌표계
            using P = complex<ll>;
            using Poly = vector<P>;
            ld abs(const P &u) {return sqrt(ld(norm(u)));} // 다른 abs와 중복 방지.
            ld arg(const P &u) {return atan2<ld,ld>(u.Y,u.X);}
            
            ll area2(const Poly &p) {
                ll s = 0;
                REP(i,0,size(p)-2) s += cross(p[i+1],p[i]);
                return s+cross(p[0],p.back());
            }
            
            struct Seg {
                P a, b;
                constexpr bool operator == (const Seg &l) const {
                    return a == l.a and b == l.b;
                }
            };
            
            struct Line {
                P a, b;
            };
        }
        
        namespace Taxi {
            ll dist(const Z::P &p, const Z::P &q) {return abs(p.X-q.X)+abs(p.Y-q.Y);}
            constexpr Z::P translate(const Z::P &p) {return {p.X+p.Y,p.Y-p.X};}
            // 좌표변환 후 벡터에 x좌표 y좌표 전부 넣고 max(max(x)-min(x),max(y)-min(y)) 구하면 지름 나옴
            // BOJ 1830 참고
        }
        
        namespace R {
            using P = complex<ld>;
            using Poly = vector<P>;
            
            constexpr bool operator == (const P &u, const P &v) {return abs(u.X-v.X) < EPS and abs(u.Y-v.Y) < EPS;}
            constexpr bool operator != (const P &u, const P &v) {return !(u == v);}
            
            struct Seg {
                P a, b;
                constexpr bool operator == (const Seg &l) const {
                    return a == l.a and b == l.b;
                }
            };
            
            struct Line {
                P a, b;
            };
        }
        
        template <typename P> constexpr auto by_xy = [](P u, P v) {return u.X == v.X ? u.Y < v.Y : u.X < v.X;};
        template <typename P, typename Poly>
        pair<Poly,Poly> convex_hull(const vector<P> &p) {
            Poly up, lo;
            constexpr static auto push = [](Poly &h, P x) {
                for (int n = size(h); n >= 2 and ccw(h[n-2],h[n-1],x) > 0; --n, h.pop_back());
                h.push_back(x);
            };
            for (int i = 0, n = size(p); i < n; ++i) push(up,p[i]), push(lo,p[n-i-1]);
            up.pop_back(), lo.pop_back();
            return MP(up,lo);
        }
        #undef X
        #undef Y
        #undef dot
        #undef cross
        #undef ccw
        #undef norm
    }
    namespace _3D {
        template <typename C>
        struct P {
            C X, Y, Z;
            P(): X(0), Y(0), Z(0) {}
            P(C x, C y, C z): X(x), Y(y), Z(z) {}
            constexpr P operator + (const P &p) const {return {X+p.X,Y+p.Y,Z+p.Z};}
            constexpr P operator - (const P &p) const {return {X-p.X,Y-p.Y,Z-p.Z};}
            constexpr P&operator +=(const P &p) {X += p.X, Y += p.Y, Z += p.Z; return *this;}
            constexpr P&operator -=(const P &p) {X -= p.X, Y -= p.Y, Z -= p.Z; return *this;}
            constexpr P operator * (const C &k) const {return {X*k,Y*k,Z*k};}
            constexpr P&operator +=(const C &k) {X *= k, Y *= k, Z *= k; return *this;}
            constexpr friend P operator * (const C &k, const P &p) {return {p.X*k,p.Y*k,p.Z*k};}
            
            constexpr bool operator == (const P &) const;
            constexpr bool operator != (const P &) const;
            
            constexpr friend istream &operator >> (istream &is, P &p) {C x, y, z; is >> x >> y >> z; p = {x,y,z}; return is;}
            constexpr friend ostream &operator << (ostream &os, const P &p) {return os << '(' << p.X << ',' << p.Y << ',' << p.Z << ')';}
            
            constexpr friend C  dot(const P &p, const P &q) {return p.X*q.X+p.Y*q.Y+p.Z*q.Z;}
            constexpr friend C norm(const P &p) {return dot(p,p);}
            constexpr friend C  abs(const P &p) {return sqrt(norm(p));}
            constexpr friend C dist(P &p, P &q) {return abs(p-q);}
        };
        constexpr bool operator == (const P<ll> &p, const P<ll> &q) {return p.X == q.X and p.Y == q.Y and p.Z == q.Z;}
        constexpr bool operator == (const P<ld> &p, const P<ld> &q) {return abs(p.X-q.X) < EPS and abs(p.Y-q.Y) < EPS and abs(p.Z == q.Z) < EPS;}
        template <typename C> constexpr bool operator != (const P<C> &p, const P<C> &q) {return !(p == q);}
    }
}
