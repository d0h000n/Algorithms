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
