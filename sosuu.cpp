#include <bits/stdc++.h>
using namespace std;

namespace /* sosuu.cpp */{
  bool is_sosuu(long long a){
    if(a<=1)return false;
    for(long long i=2; i*i<=a; i++){
      if(a%i==0)return false;
    }
    return true;
  }

  /*
  判定する数:n
  素因数分解の結果を格納する:l
  返り値:素因数の数
  */
  long long prime_fac(long long n, vector<pair<long long, long long> >&l){
    long long s = floor(sqrt(n));
    long long r;
    pair<long long, long long> x;
    for(long long i=2; i*i<=n; i++){
      if(n%i==0){
        r=0;
        do{
          r++;
          n /= i;
        }while(n%i==0);
        x = make_pair(i, r);
        l.push_back(x);
      }
    }

    if(n>1){
      x = make_pair(n, 1);
      l.push_back(x);
    }

    return l.size();
  }
}

int main(){
  long long a; cin>>a;

  bool i = is_sosuu(a);

  cout<<( i ? "素数です" : "素数じゃない" )<<endl;


  vector<pair<long long, long long> >l;
  prime_fac(a, l);

  cout<<l.at(0).first<<"^"<<l.at(0).second;
  for(long long r=1; r<(long long)l.size(); r++){
    cout<<"+"<<l.at(r).first<<"^"<<l.at(r).second;
  }
  cout<<endl;
}