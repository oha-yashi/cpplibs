/*
modpow(a, n, p) = a^n mod(p)
繰り返し2乗法
*/

#include <bits/stdc++.h>
using namespace std;
#define LIMIT 1000000007 //10^9+7

long long modpow(long long a, long long n, long long p){
  if(n==1) return a % p;
  if(n%2 == 1) return (a * modpow(a, n-1, p)) % p;
  long long t = modpow(a, n/2, p);
  return t * t % p;
}

/*
使える場面
Z = X/Y
Z mod(LIMIT) = X/Y mod(LIMIT)
Y * Y^LIMIT-2 mod(LIMIT) = 1 フェルマーの小定理
Y^LIMIT-2 mod(LIMIT) = 1/Y
>> Z mod(LIMIT) = X * Y^LIMIT-2 mod(LIMIT)
*/