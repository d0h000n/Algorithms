#include <algorithm>
using namespace std;

// (큰 집합으로 병합) + (경로 압축)
struct disjointSetUnion {
  int N;
  //follow: 집합의 크기
  //link: 집합의 대푯값
  int follow[N], link[N];
  //union 연산
  void merge(int a, int b) {
    a = find(a); b = find(b);
    if (follow[a] < follow[b]) swap(a, b);
    follow[a] += follow[b];
    link[b] = a;
  }
  //find 연산
  int find(int x) {
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
  }
  //same 연산
  inline same(int a, int b) return find(a) == find(b);
};
