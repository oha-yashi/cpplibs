#include <bits/stdc++.h>
using namespace std;

long long divisor(long long n, vector<long long> &d){
  long long cnt = 0;
  for(long long i=1; i*i<=n; i++){
    if(n%i==0){
      d.push_back(i);
      cnt++;
      if(i*i!=n){
        d.push_back(n/i);
        cnt++;
      }
    }
  }
  return cnt;
}

long long divisor_half(long long n, vector<long long> &d){
  long long cnt = 0;
  for(long long i=1; i*i<=n; i++){
    if(n%i==0){
      d.push_back(i);
      cnt++;
    }
  }
  return cnt;
}

long long divisor_sort(long long n, vector<long long> &d){
  long long cnt = divisor(n, d);
  sort(d.begin(), d.end());
  return cnt;
}

int main(){
  long long n;
  cout<<"divisor of -> ";cin>>n;
  vector<long long> d;

  long long s = divisor_half(n, d);
  for(long long x : d)cout<<x<<",";
  cout<<endl;
  d.clear();

  s = divisor(n, d);
  for(long long x : d)cout<<x<<",";
  cout<<endl;
  d.clear();
  
  s = divisor_sort(n, d);
  for(long long x : d)cout<<x<<",";
  cout<<endl;
}