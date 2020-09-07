/*
BFSとDFSで数列生成
長さNの整数列を作る
使える整数は1からM
N <= M
数列の要件は
1 <= A_1 <= A_2 ... A_N <= M
*/

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int N, M;

void showv(vi &A){
  for(int x: A)cout<<x<<",";
  cout<<endl;
}

void bfs(){
  queue<vi> que;
  que.push({});
  while(!que.empty()){
    vi read = que.front();
    que.pop();
    if(read.size()==N){
      showv(read);
    }else{
      int last = (read.empty()? 1: read.back());
      for(int i=last; i<=M; i++){
        vi next = read;
        next.push_back(i);
        que.push(next);
      }
    }
  }
}

void dfs(){
  stack<vi> stk;
  stk.push({});
  while(!stk.empty()){
    vi read = stk.top();
    stk.pop();
    if(read.size()==N){
      showv(read);
    }else{
      int last = (read.empty()? 1: read.back());
      for(int i=last; i<=M; i++){
        vi next = read;
        next.push_back(i);
        stk.push(next);
      }
    }
  }
}

int main(){
  cin>>N>>M;

  cout<<"BFS i++"<<endl;
  bfs();
  cout<<"DFS i++"<<endl;
  dfs();
}