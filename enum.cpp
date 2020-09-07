#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<(x)<<endl

enum status{NEW, PASS, END};
int main(){
  int PASS = 9;
  debug(PASS);
  debug(status::PASS);
  PASS = 1;
  debug(PASS);
  if(PASS == status::PASS){
    cout<<"PASS == status::PASS"<<endl;
  }
}

/*
PASS = 9
status::PASS = 1
PASS = 1
PASS == status::PASS
*/