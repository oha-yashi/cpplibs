#include <bits/stdc++.h>
using namespace std;

#define if_range_in(l,x,r) if(l <= x && x < r)

namespace /* in_range.cpp */ {
  template<class T>
  bool is_range_in(T l, T x, T r){
    /* l <= x < r */
    return l <= x && x < r;
  }
}

int main(){
  int l,r;cin>>l>>r;
	for(;;){
    int x;cin>>x;

    cout<<(is_range_in(l,x,r) ? "in range" : "out of range")<<endl;

    if(x==0)break;
  }
}