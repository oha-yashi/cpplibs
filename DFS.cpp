/*
ABC165-C AC
https://atcoder.jp/contests/abc165/tasks/abc165_c
深さ優先探索 : 数列を生成する
セルフ解説
https://o-treetree.hatenablog.com/entry/20200516dfs
*/

/*
概要
長さNの整数列を作る
使える整数は1からM
数列の要件は
1 <= A_1 <= A_2 ... A_N <= M

ちなみに完成した数列に一定規則で点数を与えて最大を取っている
*/

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int N, M, Q;
vi a(50), b(50), c(50), d(50);

int score(vi &A){
  //配列Aの得点を返す
  int ans = 0;
  for(int i=0; i<Q; i++){
    if(A[b[i]]-A[a[i]]==c[i])ans+=d[i];
  }
  return ans;
}

void showv(vi &A){
  for(int x: A)cout<<x<<",";cout<<endl;
}

int dfs(){
  //最大ポイントを返す
  int ans = 0;
  vector<vi> uncalced;//発見したけど計算してない配列の情報

  uncalced.push_back({});
  //初期状態を空配列にすると、最初のステップで1桁放り込める

  while(!uncalced.empty()){
    vi current = uncalced.back();//積んである最後尾の配列を読む
    //showv(current);
    uncalced.pop_back();
    //いずれにせよcurrentについての操作はもうしないので捨てる
    if(current.size()==N){
      //showv(current);
      //N桁になってたら
      //ポイント求めて
      //最大値更新
      ans = max(ans, score(current));
    }else{
      //短かったら伸ばしたのを積む
      //last : 付け足しの最小値
      int last = (current.empty()? 1: current.back());
      for(int i=last; i<=M; i++){
        //currentにiをくっつけて積む
        vi next = current;
        next.push_back(i);
        uncalced.push_back(next);
      }
    }
  }
  
  return ans;
}

int main(){
  cin>>N>>M>>Q;
  for(int i=0; i<Q; i++){
    cin>>a[i]>>b[i]>>c[i]>>d[i];
    a[i]--;
    b[i]--;
  }

  int ans = dfs();

  cout<<ans<<endl;
}