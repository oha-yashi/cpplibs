/*
拡張Euclid互除法
参考:
https://qiita.com/drken/items/b97ff231e43bce50199a
セルフ解説:
https://qiita.com/oha-yashi/items/aa98a8e31633450967ab
*/

#include <bits/stdc++.h>
using namespace std;

/* デバッグ */
#define debug(x) cout<<#x<<" = "<<(x)<<endl;

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される

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
//*/

/*
// 噛み砕いた実装
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long q = a/b;
    long long r = a%b;
    long long s, t;
    long long d = extGCD(b, r, s, t);
    x = t;
    y = s - q * x;
    return d;
}
//*/

int main(){
  long long a, b;
  cin>>a>>b;
  long long x, y;
  long long d = extGCD(a, b, x, y);
  debug(x);
  debug(y);
  debug(d);
}