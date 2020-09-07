#include <iostream>
using namespace std;

#define LIMIT 1000000007 //10^9+7

namespace /* COMfast.cpp */{
  #define COMMAX 1000000 //0.15sで構築可能
  long long fac[COMMAX], finv[COMMAX], inv[COMMAX];
  // テーブルを作る前処理
  void COMinit() {
      fac[0] = fac[1] = 1;
      finv[0] = finv[1] = 1;
      inv[1] = 1;
      for (int i = 2; i < COMMAX; i++){
          fac[i] = fac[i - 1] * i % LIMIT;
          inv[i] = LIMIT - inv[LIMIT%i] * (LIMIT / i) % LIMIT;
          finv[i] = finv[i - 1] * inv[i] % LIMIT;
      }
  }

  // 二項係数計算
  long long COM(int n, int k){
      if (n < k) return 0;
      if (n < 0 || k < 0) return 0;
      return fac[n] * (finv[k] * finv[n - k] % LIMIT) % LIMIT;
  }
}

int main() {
    // 前処理
    COMinit();

    // 計算例
    cout << COM(100000, 50000) << endl;
}