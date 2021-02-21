# Algorithms

## Contents

* Basic
* Mathmatics
* Graph
* Geometry
* Tree
* Segment Queries
* Hard Graph
* Guitar

## Basic

### DFS/BFS
#### DFS
* on Graph
```C++
vector<int> adj[N];

void dfs(int s) {
  if (visited[s]) return;
  visited[s] = true;
  for (int u : adj[s]) dfs(u);
}
```
* on Matrix
```C++
#define isIn(r,c) (0 <= r && r < R && 0 <= c && c <= C)
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
const int dr[] = {-1,-1,-1,0,0,1,1,1}, dc[] = {-1,0,1,-1,1,-1,0,1};

void dfs() {
}
```
* on Tree

#### BFS
* on Graph
* on Matrix
* on Tree

### Binary Search

### Dynamic Programming

## Mathmatics

### Sieve
