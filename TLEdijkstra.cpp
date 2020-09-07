/**
 * ダイクストラ法（非効率）
 * https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
 * これが解けるけどTLE
 * */

#include <bits/stdc++.h>
using namespace std;

#define INF 1<<29 //使いやすい無限

using vi = vector<int>;
using vvi = vector<vi>;
#define pb push_back
#define all(v) (v).begin(), (v).end()

int V,E,r;
vvi G;
vvi W;
vi dist;

//*
void TLEdijkstra(){
  vi que(V);
  for(int i=0; i<V; i++)que[i] = i;

  while(!que.empty()){
    auto itr = min_element(all(que),[](int a, int b){
      return dist[a] < dist[b];
    });
    int now = *itr;
    que.erase(itr);

    for(int i=0; i<G[now].size(); i++){
      int next = G[now][i];
      int nextW = W[now][i];

      dist[next] = min(dist[next], dist[now] + nextW);
    }
  }
}
//*/

int main(){
  cin>>V>>E>>r;
  G.resize(V);
  W.resize(V);

  for(int i=0; i<E; i++){
    int s,t,d;
    cin>>s>>t>>d;
    G[s].pb(t);
    W[s].pb(d);
  }

  dist.resize(V, INF);
  dist[r] = 0;
  TLEdijkstra();
  for(int x: dist){
    if(x==INF){
      cout<<"INF"<<endl;
    }else{
      cout<<x<<endl;
    }
  }
}