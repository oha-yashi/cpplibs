#include <bits/stdc++.h>
using namespace std;

/*
Union Find 木
[AtCoder ABC 120 D - Decayed Bridges (400 点) - けんちょんの競プロ精進記録](https://drken1215.hatenablog.com/entry/2019/03/03/224600)
[競プロ覚書：Union-Find まとめ - プログラミング日記](https://pyteyon.hatenablog.com/entry/2019/03/11/200000)
[Union-Find Tree を理解する！素集合系を扱うデータ構造 | アルゴリズムロジック](https://algo-logic.info/union-find-tree/)
*/

template<class T>/* 大抵intでいい */
class UnionFind {
  /* 
  par[i]<0 : iが持っているサイズ = -par[i] 
  par[i]>=0: iの親 = par[i]
  */
  vector<T> par;
public:
  UnionFind(T n) : par(n, -1) { }
  void init(T n) { par.assign(n, -1); }
  
  T root(T x) {
    if (par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }
  
  bool isSame(T x, T y) {
    return root(x) == root(y);
  }
  
  bool merge(T x, T y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y); // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  
  T size(T x) {
    return -par[root(x)];
  }
};