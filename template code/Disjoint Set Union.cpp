#include <algorithm>
using namespace std;

// (큰 집합으로 병합) + (경로 압축)
struct DSU {
  int N;
  //size: 집합의 크기
  //head: 집합의 대푯값
  int follow[N], head[N];
  //초기화
  void init() {
    fill_n(size, N, 1);
    for (int i = 1; i < N; ++i) head[i] = i;
    return;
  }
  //union 연산
  //same(a, b) == false여야 호출한다
  void merge(int a, int b) {
    a = find(a); b = find(b);
    if (size[a] < size[b]) swap(a, b);
    size[a] += follow[b];
    head[b] = a;
    return;
  }
  //find 연산
  int find(int x) {
    if (x == head[x]) return x;
    return head[x] = find(head[x]);
  }
  //same 연산
  inline int same(int a, int b) return find(a) == find(b);
};
