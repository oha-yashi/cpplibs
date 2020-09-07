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

bool check(string S, string T){

  bool can_skip;
  int sl = S.length();
  int tl = T.length();

  if(sl > tl)return false;
  if(sl == tl)return S==T;

  vector<regex> rlist;
  for(int i=0; i<=sl; i++){
    string s = S;
    s.insert(i, ".");
    //debug(s);
    rlist.push_back(regex(s));
  }

  smatch m;
  bool ans = false;
  for(int i=0; i<rlist.size(); i++){
    if(regex_search(T, m, rlist[i])){
      //DEBUG(i);
      ans=true;
    }
  }
  return ans;
}

int main(){
	int N;cin>>N;
  string S;cin>>S;
  while(N--){
    string T;cin>>T;
    bool ok = check(S,T);
    cout<<(ok?"valid":"invalid")<<endl;
  }
}