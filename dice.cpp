#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define LIMIT 1000000007 //10^9+7
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(v) (v).begin(), (v).end()

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

struct Dice{
  int u,d,r,l,f,b;
  Dice(int u,int d,int r,int l,int f,int b)
    :u(u), d(d), r(r), l(l), f(f), b(b) {}

  void get(){
    cout<<"u = "<<u<<endl;
    cout<<"d = "<<d<<endl;
    cout<<"r = "<<r<<endl;
    cout<<"l = "<<l<<endl;
    cout<<"f = "<<f<<endl;
    cout<<"b = "<<b<<endl;
  }

  void U(){
    swap(u,f);swap(f,d);swap(d,b);
  }
  void D(){
    swap(u,b);swap(b,d);swap(d,f);
  }
  void R(){
    swap(u,l);swap(l,d);swap(d,r);
  }
  void L(){
    swap(u,r);swap(r,d);swap(d,l);
  }
};

int main(){
	int N,H,W,sy,sx;cin>>N>>H>>W>>sy>>sx;
  sy--;sx--;

  Dice dice(1,6,4,3,5,2);
  
  string s;cin>>s;

  vector<vi> ans(H, vi(W,0));

  //初期
  ans[sy][sx] = dice.d;

  for(int i=0; i<N; i++){
    char c = s[i];
    switch(c){
      case 'U': dice.U(); sy--; ans[sy][sx] = dice.d; break;
      case 'D': dice.D(); sy++; ans[sy][sx] = dice.d; break;
      case 'R': dice.R(); sx++; ans[sy][sx] = dice.d; break;
      case 'L': dice.L(); sx--; ans[sy][sx] = dice.d; break;
    }
  }

  rep(i,H){
    debug(ans[i]);
  }
}