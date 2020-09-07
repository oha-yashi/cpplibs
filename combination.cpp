#include <bits/stdc++.h>
using namespace std;

//#define LIMIT 10007 //小さい素数LIMIT
//#define LIMIT 100000007 //10^8+7
//#define LIMIT 100000000003 //10^11+3
//#define LIMIT 1000000000000037 //10^15+37 l_nCrはオーバーフローする
#define LIMIT 1000000007 //10^9+7

namespace /* combination.cpp */{
  namespace /* modinv.cpp */{
    namespace /* extGCD.cpp */{
      long long extGCD(long long a, long long b, long long &x, long long &y) {
          if (b == 0) {
              x = 1;
              y = 0;
              return a;
          }
          long long d = extGCD(b, a%b, y, x);
          y -= a/b * x;
          return d;
      }
    }
    long long modinv(long long a, long long p){
      long long x, y;
      extGCD(a, p, x, y);
      return (x>0? x: x+p);
    }
  }
  long long l_fac(long long n){
    if(n<0) return -1;
    long long ans = 1;
    for(long long i=1; i<=n; i++){
      ans *= i;
      ans %= LIMIT;
    }
    return ans;
  }
  long long l_nPr(long long n, long long r){
    long long ans = 1;
    for(long long i=0; i<r; i++){
      ans *= (n-i);
      ans %= LIMIT;
    }
    return ans;
  }
  long long l_nCr(long long n, long long r){
    return l_nPr(n, r) * modinv(l_fac(r), LIMIT) % LIMIT;
  }
}

/* 階乗 */
//n>20 -> overflow
long long fac(long long n){
  if(n>20){
    cout<<"over flow ";
    return -1;
  }
  if(n<0) return -1;
  long long ans = 1;
  for(long long i=1; i<=n; i++){
    ans *= i;
  }
  return ans;
}

/* 順列 */
//50P10程度が限界
long long nPr(long long n, long long r){
  long long ans = 1;
  for(long long i=0; i<r; i++){
    ans *= (n-i);
  }
  return ans;
}

/* 組み合わせ */
long long nCr(long long n, long long r){
  if(n<r) return 0;
  if(r > n/2) r = n-r;
  return nPr(n, r) / fac(r);
}

#define debug(x) cout<<(#x)<<" = "<<(x)<<endl;

int main(){
  long long n, r;
  cin>>n>>r;
  debug(LIMIT);
  debug(fac(n));
  debug(l_fac(n));
  debug(fac(r));
  debug(l_fac(r));
  debug(nPr(n, r));
  debug(l_nPr(n, r));
  debug(nCr(n, r));
  debug(l_nCr(n, r));
}