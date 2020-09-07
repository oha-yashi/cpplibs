#include <bits/stdc++.h>
using namespace std;

/* gcd: 最大公約数 */
/* lcm: 最小公倍数 */

//c++17から、stdにgcdとlcmが実装されている
//*
long long gcd(long long a, long long b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

long long lcm(long long a, long long b){
  return a*b / gcd(a, b);
}
//*/

/*
int gcd_arr(vector<int>& a){
  int n = a.size();
  if(n==2){
    return gcd(a[0], a[1]);
  }else{
    a[n-2] = gcd(a[n-2], a[n-1]);
    a.pop_back();
    return gcd_arr(a);
  }
}

int lcm_arr(vector<int>& a){
  int n = a.size();
  if(n==2){
    return lcm(a[0], a[1]);
  }else{
    a[n-2] = lcm(a[n-2], a[n-1]);
    a.pop_back();
    return lcm_arr(a);
  }
}
//*/

namespace /*gcd_lcm.cpp*/{
  int gcd_arr(vector<int> &a){
    int n = a.size();
    for(int i=n-2; i>=0; i--){
      a[i] = gcd(a[i], a[i+1]);
    }
    return a.front();
  }

  int lcm_arr(vector<int> &a){
    int n = a.size();
    for(int i=n-2; i>=0; i--){
      a[i] = lcm(a[i], a[i+1]);
    }
    return a.front();
  }
}

int main(){
  vector<int> a;
  cout<<"input nums>0, n<=0 to end\n";
  int b;
  cin>>b;
  while(b>0){
    a.push_back(b);
    cin>>b;
  }
  vector<int> c;
  c = a;
  cout<<"gcd = "<<gcd_arr(c)<<endl;
  for(int x:c)cout<<x<<",";cout<<endl;
  c = a;
  cout<<"lcm = "<<lcm_arr(c)<<endl;
  for(int x:c)cout<<x<<",";cout<<endl;
}
/*test case
24 18 42 12 0
gcd = 6
lcm = 504
*/