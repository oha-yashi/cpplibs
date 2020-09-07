/**
 * DFSの訪問順序
 * ord_pre : 行きがけ
 * ord_pos : 帰りがけ
 * lowlink : lowlink
 * */

#include <bits/stdc++.h>
using namespace std;
#define INF 1<<29 //使いやすい無限

using vi = vector<int>;
using vvi = vector<vi>;

#define debugv(v) do{for(auto x:(v)) cout<<x<<","; cout<<endl;}while(0)

int V,E;
int pre, pos;
vvi G;
vi ord_pre;
vi ord_pos;
vi lowlink;

void dfs(int start){
  stack<int> st;
  st.push(start);

  while(!st.empty()){
    int u = st.top();st.pop();
    ord_pre[u] = pre++;

    for(int v: G[u]){
      if(ord_pre[v]!=INF)continue;
      st.push(v);
    }
  }
}

void recdfs(int p, int u){
  lowlink[u] = ord_pre[u]= pre++;

  for(int v: G[u]){
    if(ord_pre[v]==INF){
      recdfs(u, v);

      lowlink[u] = min(lowlink[u], lowlink[v]);
    }else if(v!=p){
      lowlink[u] = min(lowlink[u], ord_pre[v]);
    }
  }

  ord_pos[u] = pos++;

}

int main(){
  cin>>V>>E;
  G.resize(V);
  for(int i=0; i<E; i++){
    int s,t;
    cin>>s>>t; //s--;t--;
    G[s].push_back(t);
    G[t].push_back(s);
  }

  ord_pre.assign(V, INF);
  pre = 0;
  for(int i=0; i<V; i++)if(ord_pre[i]==INF){
    dfs(i);
  }
  debugv(ord_pre);

  ord_pre.assign(V, INF);
  ord_pos.assign(V, INF);
  lowlink.assign(V,INF);
  pre = pos = 0;
  for(int i=0; i<V; i++)if(ord_pre[i]==INF){
    recdfs(-1, i);
  }
  debugv(ord_pre);
  debugv(ord_pos);
  debugv(lowlink);
}