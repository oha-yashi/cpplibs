#include <bits/stdc++.h>
using namespace std;

namespace /* XOR.cpp */{
  /* [0, n]の累積XOR */
  long long cumulative(long long n){
    if(n%2) return (n+1)/2%2;
    else return n ^ cumulative(n-1);
  }

  /* [A, B]の累積XOR */
  long long rangeXOR(long long A, long long B){
    return cumulative(A-1) ^ cumulative(B);
  }
}

int main(){
  cout<<"input 'a b (a <= b)'"<<endl;
  long long a,b;cin>>a>>b;
  cout<<"cumu(a) = "<<cumulative(a)<<endl;
  cout<<"cumu(b) = "<<cumulative(b)<<endl;
  cout<<"rangeXOR(a,b) = "<<rangeXOR(a,b)<<endl;
}