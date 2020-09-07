#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  cout<<"*a.begin() = "<<*a.begin()<<endl;
  cout<<"*(a.begin()+5) = "<<*(a.begin()+5)<<endl;
  cout<<"a[5] = "<<a[5]<<endl;
  auto itr = lower_bound(a.begin(), a.end(), 6);
  cout<<"itr = lower_bound(a.begin(), a.end(), 6) = "<<*itr<<endl;
  int d = distance(a.begin(), itr);
  cout<<"distance(a.begin(), itr) = "<<d<<endl;
}

/*
*a.begin() = 1
*(a.begin()+5) = 6
a[5] = 6
itr = lower_bound(a.begin(), a.end(), 6) = 6
distance(a.begin(), itr) = 5
*/