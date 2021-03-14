# Algorithms

## Contents

* Basic
* Mathmatics
* Graph
* Geometry
* Tree
* Range Queries
* Hard Graph
* Guitar

## Basic

### DFS/BFS
#### DFS
* on Graph/Tree
```C++
vector<int> adj[N];
bool visited[N];
```
```C++
//on Graph
void dfs(int s) {
  if (visited[s]) return;
  visited[s] = true;
  for (int u : adj[s]) dfs(u);
}
//on Tree
void dfs(int s, int e) {
  for (auto u : adj[s]) if (u != e) {
    dfs(u,s);
  }
}
```
* on Matrix
```C++
using ci = complex<int>;
#define isIn(p) (0 <= p.real() && p.real() < R && 0 <= p.imag() && p.imag() < C)
#define P(p) (p).real()][(p).imag()
const ci move[] {{0,1},{1,0},{0,-1},{-1,0}};
bool visited[R][C];
```
```C++
void dfs(ci s) {
  if (!isIn(s) || visited[P(s)]) return;
  visited[P(s)] = true;
  for (auto m : move) dfs(s+m);
}
```

#### BFS
* on Graph
* on Matrix
* on Tree

### Binary Search

### Dynamic Programming
#### Update
```C++
void update(int idx, int frm, int val) {
  dp[idx] = val;
  rdp[idx] = frm;
}
```
#### track
```C++
void track(int idx, vector<int>& ans) {
  if (idx != start_idx) track(rdp[idx]);
  ans.push_back(dp[idx]);
}
```
## Mathmatics

### Sieve

## Range Queries
### Segment Tree
```C++
using ii = pair<int,int>; using iii = tuple<int,int,int>;
```
구간을 나타내기 위해 (정수,정수) 쌍이 필요하다.
노드는 노드 번호와 커버하는 구간의 정보로 이루어진다. 따라서 (정수,정수,정수) 쌍이 필요하다.
```C++
int sumTree[N];
```
이름이 `tree`만 아니면 된다. 함수 내에서 `tree`라는 이름을 이미 사용하고 있기 때문이다.
```C++
int msb = 32; while (msb--) if (n>>msb) break;
length = 1<<(msb+bool(n&(n-1)));
```
MSB란 Most Significant Bit의 약자로, 최상위 비트를 뜻한다. 따라서 지금 `length`에 넣고자 하는 것은 $log_2$
```C++
fill_n(sumTree,n<<1,0);
```
구간 트리는 실제로 사용하는 인덱스가 1~2n-1까지다. 따라서 0번 인덱스를 사용하지 않는다.
이 점을 생각하면 `sumTree[0]`에 해당 operation의 항등원인 0를 담고있게 하자.
```C++
auto oper = [&](int a, int b) {return a+b;};

```
```C++
void build() {
}
```
```C++
template <typename T>
auto query(ii range, iii node, T tree[], function<T(const T& a, const T& b)> op) {
  auto [s,e] = range; auto [k,l,r] = node;
  if (r < s || e < l) return tree[0];
  if (l <= s && e <= r) return tree[k];
  int m = (l+r)>>1;
  return op(query(range, {k<<1,    l,  m}, tree, op),
            query(range, {(k<<1)+1,m+1,r}, tree, op));
}
```
```C++
template <typename T>
void update(int t, T x, T tree[], function<T(const T& a, const T& b)> op) {
  for (tree[t += length-1] = x; t > 1; t >>= 1)
    tree[t>>1] = op(tree[t], tree[t^1]);
}
```
