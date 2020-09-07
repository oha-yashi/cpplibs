#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> v = {3, 1, 4, 5, 2};

  //昇順でソート
  std::sort(v.begin(), v.end(), [](int a, int b){
    return a > b;
  });

  // コンテナvから、偶数をすべて削除する
  std::erase_if(v, [](int x) { return x % 2 == 0; });

  for (int x : v) {
    std::cout << x << std::endl;
  }
}