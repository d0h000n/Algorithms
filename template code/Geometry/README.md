```C++
namespace Geometry {
  // Code by hgmhc.
    // Reference: https://zigui.tistory.com/34, ntopia TeamNote, Guide to CP, CP book 3
}
```
로 이루어져 있다.

위 템플릿은 진지빨고 기하 할 때 쓰라고 만든거고,
템플릿을 들고 갈 수 없는 대회 환경에서는 아래와 같이 가볍게 이용해야 한다.
```C++
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
```
* Pick's theorem: S=I+B/2-1
* Heron's formula: S=√p(p-a)(p-b)(p-c), p=(a+b+c)/2
* 
