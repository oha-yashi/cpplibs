/**
 * 単一始点最短経路
 * https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
 * ダイクストラ法
 * */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define INF 1LL<<60 //使いやすい無限(ll)

/* 詳細なグラフ定義 */
using Node = long long; //頂点
using Distance = long long; //距離
using Weight = long long; //重み
using Edge = pair<Node, Weight>; //辺
using Graph = vector<vector<Edge>>; //隣接リスト

ll V,E,r;
Graph G;
vector<Distance> dist;

void dijkstra(Node start){
  priority_queue<
    pair<Distance, Node>,
    vector<pair<Distance, Node>>,
    greater<pair<Distance, Node>>
    //Distanceの小さいものから取り出す
  >que;

  dist.resize(V, INF);
  dist[start] = 0;
  que.push({0, start}); //距離0の頂点rを入れる

  while(!que.empty()){
    Distance nowDist;
    Node nowNode;
    tie(nowDist, nowNode) = que.top(); que.pop();
    if(nowDist > dist[nowNode])continue;

    for(Edge next: G[nowNode]){
      Node nextDir = next.first;
      Weight nextWeight = next.second;

      if(dist[nextDir] <= dist[nowNode]+nextWeight)continue;
      dist[nextDir] = dist[nowNode] + nextWeight;
      que.push({dist[nextDir], nextDir});
    }
  }
}

int main(){
  cin>>V>>E>>r;
  G.resize(V);

  for(int i=0; i<E; i++){
    int s,t,d;
    cin>>s>>t>>d;
    G[s].push_back({t, d});
  }

  dijkstra(r);

  for(ll x: dist){
    if(x==INF){
      cout<<"INF"<<endl;
    }else{
      cout<<x<<endl;
    }
  }
}