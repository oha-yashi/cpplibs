#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a = {7, 3, 9, 12, 1, 6, 4, 8, 7, 8};
  sort(a.begin(), a.end());
  cout<<"ソート済み"<<endl;
  for(int x: a){
    cout<<x<<", ";
  }
  cout<<endl;
  
  cout<<"find -> ";
  int b;
  cin>>b;
  auto itr = lower_bound(a.begin(), a.end(), b);
  int d = distance(a.begin(), itr);
  cout<<b<<"以上の値が出る最初の場所は"<<d+1<<"番目の"<<*itr<<endl;
}