namespace Geometry {
    namespace Taxi {
        ;
    }
    namespace Z_2D {
        using C = long long;
        struct P {C X, Y;
            P operator + (const P& other) const {return P {X+other.X, Y+other.Y};}
            P operator - (const P& other) const {return P {X-other.X, Y-other.Y};}
        };
        C cross(const P& p, const P& q) {return p.X*q.Y-q.Y*p.X;}
    }
    namespace R_2D {
        using C = long double;
        const C EPS = 1e-9, PI = acos(-1);
        struct P {C X, Y;
            P operator + (const P& v) const {return P {X+v.X, Y+v.Y};}
            P operator - (const P& v) const {return P {X-v.X, Y-v.Y};}
            P operator * (const C& k) const {return C {X*k, Y*k};}
            P operator / (const C& k) const {return C {X/k, Y/k};}
            P rotate(const C&) const {}
        }
        struct Line {
            ;
        };
        struct Circle {P p; C r;
            C area() {return PI*r*r;}
        };
        bool operator == (P& p, P& q) {
            return abs(p-q) < 1e-9;
        }
        C dist(const P& p, const P& q) {return hypot(p.X-q.X, p.Y-q.Y);}
        void rotate(P& v, const C& theta) {v *= polar((C)1.0,a);}
        C cross(const P& p, const P& q) {return (conj(p)*q).Y;}
        C angle(const P& p) {return arg(p);}
        C angle(const P& p, const P& q) {return arg(p)-arg(q);}
        P make_vector(const C& len, const C& ang) {return polar(len,ang);}
    }
}

/*
템플릿이 없을 때 이용하는 <complex> 라이브러리의 간결한 함수들
using C = long double;
using P = complex<C>;
#define X real()
#define Y imag()
const C EPS = 1e-9, PI = acos(-1);
// (거리) = abs(p-q)
// (외적) = (conj(p)*q).Y
// (각도) = arg(p)
// (벡터 생성): polar(길이,각도)
// (회전): v*polar(1.0,각도)
*/

//using namespace Geometry::R_2D;와 같은 식으로 선언 후에 자유롭게 사용할 수 있다.
