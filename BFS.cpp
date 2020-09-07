/*
ABC151-D AC in 10ms
https://atcoder.jp/contests/abc151/tasks/abc151_d
幅優先探索 : 最短距離を求める
参考　: https://qiita.com/drken/items/6a95b57d2e374a3d3292#4-2-%E3%82%B0%E3%83%A9%E3%83%95%E4%B8%8A%E3%81%AE%E6%8E%A2%E7%B4%A2
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pii;

int H, W;
vector<string> S(20);
void input(){
  cin>>H>>W;
  for(int i=0; i<H; i++){
    cin>>S[i];
  }
}

//4方向の移動を示す
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int bfs(int sx, int sy){
  //(sx, sy)からの最大距離を返す
  int ans = 0;
  vector<vector<int>> dist(H, vector<int>(W, -1)); //dist=-1のマスは未発見
  queue<Pii> unvisited; //発見したけど訪問していないマスの情報
  /*
  pushは後ろから入れる
  popは先頭から出す
  */

  dist[sx][sy] = 0; //スタートを発見
  unvisited.push(Pii(sx, sy)); //訪問はしてないのでスタートを入れる

  //探索開始
  while(!unvisited.empty()){
    //unvisitedが空になるまで
    pair<int, int> current = unvisited.front(); //先頭を読む
    unvisited.pop(); //先頭を捨てる
    int x = current.first;
    int y = current.second;

    for(int i=0; i<4; i++){
      //4方向にnextを探索
      int next_x = x + dx[i];
      int next_y = y + dy[i];
      if(next_x<0 || next_x>=H || next_y<0 || next_y>=W) continue; //外に出たらダメ
      if(S[next_x][next_y]=='#') continue; //壁はダメ

      if(dist[next_x][next_y] == -1){
        //未発見だったらこれで発見なので未訪問キューに入れる
        unvisited.push(Pii(next_x, next_y));
        dist[next_x][next_y] = dist[x][y] + 1; //nextのdistは現在地+1
        ans = max(ans, dist[next_x][next_y]);
      }
    }
  }
  return ans;
}

int main(){
  input();
  int ans = 0;

  for(int sx=0; sx<H; sx++)for(int sy=0; sy<W; sy++){
    if(S[sx][sy]=='.'){
      //スタートにできるとき      
      ans = max(ans, bfs(sx, sy));
    }
  }

  cout<<ans<<endl;
}