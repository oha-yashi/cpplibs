/*
有向グラフを探索
topoBFS : 
  BFSでトポロジカルソート
  閉路があるとソート後の頂点数が減る(閉路検出)
  各頂点への最長最短経路長がわかる
recDFS : 
  再帰DFSでトポロジカルソート
  閉路なしが前提
  各頂点からどれだけ下に潜れるかがわかる
  閉路検出できるように->
  http://www.prefield.com/algorithm/graph/topological_sort.html
閉路なし -> DAG(有向無閉路グラフ) -> トポロジカルソート可能

入力
N M
f1 t1
f2 t2
...
fM tM

ex1 閉路なし
7 8
1 2 1 4 2 3 2 5 4 3 5 7 6 4 6 5
ex2 閉路あり
7 9
1 2 1 4 2 3 2 5 4 3 5 7 6 4 6 5 7 2
(2->5->7->2ループあり)

*/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define debug2(x,y) cout<<"("<<#x<<","<<#y<<") = ("<<(x)<<","<<(y)<<")\n"

namespace /*DAG.cpp*/{
  int N,M; //頂点と辺の数
  vector<vector<int>> G; //グラフ
  vector<int> h; //入次数 : topoBFS
  vector<int> l_depth; //最大経路長 //recDFSでは探索済みかどうかも示す
  vector<int> s_depth; //最短経路長
  vector<int> ans; //答えを格納(recDFSではreverse必要)

  void input(){
    cin>>N>>M;
    G.resize(N);
    h.resize(N, 0);
    int f,t;
    for(int i=0; i<M; i++){
      cin>>f>>t;
      f--;t--;
      G[f].push_back(t); //recDFSとtopoBFS両方に必要
      h[t]++; //topoBFSにのみ必要
    }
  }

  void topoBFS(){   
    queue<int> unchecked;
    for(int i=0; i<N; i++){
      if(h[i]==0){
        unchecked.push(i);
        l_depth[i] = 0;
        s_depth[i] = 0;
      }
    }
    while(!unchecked.empty()){
      int current = unchecked.front();
      unchecked.pop();
      ans.push_back(current+1);
      for(int next: G[current]){
        h[next]--;

        l_depth[next] = max(l_depth[next], l_depth[current]+1); //最長経路長
        s_depth[next] = min(s_depth[next], s_depth[current]+1); //最短経路長

        if(h[next]==0){
          unchecked.push(next);
        }
      }
    }
  }

  enum status{NEW, PASS, END};
  vector<enum status> st(N, NEW);
  void recDFS(int look){
    if(l_depth[look]!=-1) return;
    if(G[look].size()){
      for(int next: G[look]){
        recDFS(next);
        l_depth[look] = max(l_depth[next]+1, l_depth[look]);
        s_depth[look] = min(s_depth[next]+1, s_depth[look]);
      }
    }else{
      l_depth[look] = 0;
      s_depth[look] = 0;
    }
    ans.push_back(look+1);
  }
}

int main(){
  input();

  cout<<"topoBFS"<<endl;
  l_depth.resize(N, -1);
  s_depth.resize(N, N);
  topoBFS();
  for(int x: ans){
    cout<<x<<",";
  }cout<<" -> ";
  bool isDAG = ans.size()==N;
  cout<<(isDAG? "閉路なし": "閉路あり")<<endl;

  if(isDAG){
    //DAGなら経路長を示してrecDFSでも実行
    cout<<"long path  -> ";
    for(int x: l_depth){
      cout<<x<<",";
    }cout<<endl;
    cout<<"short parh -> ";
    for(int x: s_depth){
      cout<<x<<",";
    }cout<<endl;

    int l_max = *max_element(l_depth.begin(), l_depth.end());
    int s_max = *max_element(s_depth.begin(), s_depth.end());
    debug(l_max);

    ans.clear();
    l_depth.clear();
    s_depth.clear();

    //recDFS
    cout<<"recDFS"<<endl;
    l_depth.resize(N, -1);
    s_depth.resize(N, N);

    for(int i=0; i<N; i++){
      recDFS(i);
    }
    reverse(ans.begin(), ans.end());
    for(int x: ans){
      cout<<x<<",";
    }cout<<endl;

    cout<<"long depth  -> ";
    for(int x: l_depth){
      cout<<x<<",";
    }cout<<endl;
    cout<<"short depth -> ";
    for(int x: s_depth){
      cout<<x<<",";
    }cout<<endl;
  }
}