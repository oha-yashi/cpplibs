#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define LIMIT 1000000007 //10^9+7
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(v) (v).begin(), (v).end()
/* 一括cin */
template<class H>
void CIN(H& h){cin>>h;}
template<class H, class... T>
void CIN(H &h, T&... t){cin>>h;CIN(t...);}
/* デバッグ */
namespace /* debug */{
  #define DEBUG(...) do{cout<<#__VA_ARGS__<<" = ";debug(__VA_ARGS__);}while(0) //変数
  #define ldebug(...) do{cout<<"["<<setw(3)<<__LINE__<<"] ";debug(__VA_ARGS__);}while(0) //行数
  #define lDEBUG(...) do{cout<<"["<<setw(3)<<__LINE__<<"] "<<#__VA_ARGS__<<" = ";debug(__VA_ARGS__);}while(0) //変数, 行数
  template<class T>void show(T&x){cout<<x<<" ";} //出力
  template<class T>void showendl(T&x){cout<<x<<endl;} //出力改行
  template<class P,class Q>void show(pair<P,Q>&x){cout<<"("<<x.first<<", "<<x.second<<") ";} //pair出力
  template<class P,class Q>void showendl(pair<P,Q>&x){cout<<"("<<x.first<<", "<<x.second<<")"<<endl;} //pair出力改行
  template<class H>void debug(H&&h){showendl(h);} //引数1つ
  template<class H,class...Ts>void debug(H&&h,Ts&&...ts){show(h);debug(forward<Ts>(ts)...);} //可変引数
  template<class T>void debug(vector<T>&vt){int i=0;for(auto x:vt)++i!=vt.size()?show(x):showendl(x);} //vector出力
  template<class T>void debug(initializer_list<T>init){int i=0;for(auto x:init)++i!=init.size()?show(x):showendl(x);} //初期化子リスト出力
}

void solve(){

}

int main(){
  int t = 1;
  cin>>t;
  while(t--)solve();
}

/* デフォで冒頭に書く */

#define INF 1<<29 //無限
#define INF 1LL<<60 //無限(ll)

const double PI = acos(-1);

using vvi = vector<vi>;
using vb = vector<bool>;
using pii = pair<int,int>;
using mii = map<int,int>;

#define pb push_back
#define vmin(v) *min_element(all(v))
#define vmax(v) *max_element(all(v))

/* 詳細なグラフ定義 */
using Node = long long; //頂点
using Distance = long long; //距離
using Weight = long long; //重み
using Edge = pair<Node, Weight>; //辺
using Graph = vector<vector<Edge>>; //隣接リスト

#define endl '\n'

#define prifln(...) printf(__VA_ARGS__);printf("\n")

/*
  coutで桁数大きい小数を出力するとき
  デフォだと小数は6桁しか出ない
*/
int _main(){
  cout<<fixed<<setprecision(10);
  //高速化
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int CEIL(int a, int b){
  //ceil(a/b)
  return (a+b-1)/b;
}