/*
ABC153-E AC
https://atcoder.jp/contests/abc153/tasks/abc153_e
動的計画法 DP
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, n;
  cin>>h>>n;
  int INF = 1<<29;

  //必要なdp配列をとって初期化する
  vector<int> dp(h+10010, INF);
  //初期値を入れる
  dp[0] = 0;

  int a, b;
  for(int rp=0; rp<n; rp++){
    cin>>a>>b;
    for(int i=0; i<=h; i++){
      //端からi++しながらdpを見ていく
      //ここがメインの漸化式
      dp[i+a] = min(dp[i+a], dp[i]+b);
    }
  }

  //問題の条件から最小値を引っ張る
  //範囲がdp[h]以降
  int ans = *min_element(dp.begin()+h, dp.end());
  cout<<ans<<endl;
}