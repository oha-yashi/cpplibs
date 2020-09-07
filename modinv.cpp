#include <bits/stdc++.h>
using namespace std;

/*
mod pでの a の逆元 x
ax = 1 mod p
ax-1がpで割り切れるので
ax + py = 1 の解 x をとる
aとpは互いに素であること
*/

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

#define debug(x) cout<<(#x)<<" = "<<(x)<<endl;

int main(){
  int a, b;
  cin>>a>>b;
  debug(modinv(a, b));  
}