#include <bits/stdc++.h>
using namespace std;

int a[13] = {1,3,7,10,15,27,50,55,63,77,89,95,101};

namespace /* binary_search */{
  bool check(long long n){
    if(a[n]<50)return true;
    else return false;
  }

  long long binary_search(long long ok, long long ng){
    while(abs(ok-ng)>1){
      long long mid = (ok + ng)/2;
      if(check(mid)){
        ok = mid;
      }else{
        ng = mid;
      }
    }
    return ok;
  }
}

int main(){
  cout<<binary_search(-1,13)<<endl;
}