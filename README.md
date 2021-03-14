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
MSB란 Most Significant Bit의 약자로, 최상위 비트를 뜻한다.
따라서 지금 `length`에 넣고자 하는 것은 2^(⎡㏒₂𝑛⎤), 즉 `length`보다 작지않은 최소의 2의 거듭제곱수이다.
```C++
fill_n(sumTree,n<<1,0);
```
구간 트리는 실제로 사용하는 인덱스가 1~2n-1까지다. 따라서 0번 인덱스를 사용하지 않는다.
이 점을 생각하면 `sumTree[0]`에 해당 operation의 항등원인 0를 담고있게 하자.
그와 동시에, 아무것도 담기지 않은 초기의 상태에는 `build`를 호출하지 않는 한 `fill_n`을 이용하여 항등원으로 채워주어야 한다.
```C++
auto oper = [&](const int a, const int b) {return a+b;};
```
구간 트리 내에서 수행되는 연산의 종류이다. 함수의 포인터를 보내야 하므로 람다를 이용하면 편리하게 구현할 수 있다.
```C++
void build() {
}
```
일단은 생략한다. Knapsack의 메모리 최적화 아이디어와 동일하다.
```C++
template <typename T>
auto query(ii range, iii node, T tree[], function<T(const T& a, const T& b)> op) {
  auto [s,e] = range; auto [k,l,r] = node;
  if (r < s || e < l) return tree[0];
  if (l <= s && e <= r) return tree[k];
  int m = (l+r)>>1;
  return op(query(range, {k<<1,    l,  m}, tree, op),
            query(range, {(k<<1)|1,m+1,r}, tree, op));
}
```
대망의 `query`함수이다. 맨 처음 호출할 때 `query({s,e}, {1,1,n}, sumTree, oper)`로 작성하면 ㅈ된다는 사실을 알아야 한다.

재귀로 `length`를 설정하지 않고, `n`이 2의 거듭제곱수가 아닌 상황에서는
기저 배열의 Level이 조금씩 위에 있는 상태가 가능하다. 그러면 `update`에서 조져버린다.

따라서 Level이 모두 최하위로 맞춰질 수 있도록 `query({s,e}, {1,1,length}, sumTree, oper)`로 호출해주어야 한다.
```C++
template <typename T>
void update(int t, T x, T tree[], function<T(const T& a, const T& b)> op) {
  for (tree[t += length-1] = x; t > 1; t >>= 1)
    tree[t>>1] = op(tree[t], tree[t^1]);
}
```
`t`는 target의 줄임말. 깰꼼하게 코드가 나오는데... 이게 상향식 하향식 짬뽕이라 거지같은 면도 있다.



```C++
auto query(ii range, iii node, int tree[], function<int(const int& a, const int& b)> op) {
  auto [s,e] = range; auto [k,l,r] = node;
  if (r < s || e < l) return tree[0];
  if (l <= s && e <= r) return tree[k];
  int m = (l+r)>>1;
  return op(query(range, {k<<1,l,m}, tree, op), query(range, {(k<<1)|1,m+1,r}, tree, op));
}

void update(int t, int x, iii node, int tree[], function<int(const int& a, const int &b)> op) {
  auto [k,l,r] = node;
  if (r < t || t < l) return;
  if (l == r) {tree[k] = x; return;}
  int m = (l+r)>>1;
  update(t,x,{k<<1,l,m},tree,op); update(t,x,{(t<<1)|1,m+1,r},tree,op);
  tree[k] = op(tree[k<<1],tree[(k<<1)|1]);
}

void solve() {
  int n; cin >> n;
  fill_n(sumTree, n<<2, 0);
}
```
```
