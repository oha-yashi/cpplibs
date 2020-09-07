#include <bits/stdc++.h>
using namespace std;

/**
 * 座標圧縮
 * */

namespace /* ZahyoComp.cpp */ {
  template<class T>
  vector<T> compress(vector<T> &V){
    //Vを圧縮後の値にする 元の値を得るために重複削除ソート列であるSを返す
    vector<T> S = V;
    sort(S.begin(), S.end());
    S.erase( unique(S.begin(), S.end()), S.end() );
    for(int i=0; i<V.size(); i++){
      V[i] = lower_bound(S.begin(), S.end(), V[i]) - S.begin();
    }
    return S;
  }

  template<class T>
  vector<T> compress(vector<T> &V1, vector<T> &V2){
    //2つのVを一緒くたにして各々圧縮する 重複削除ソート列Sを返す
    vector<T> S;
    int N = V1.size();
    copy(V1.begin(), V1.end(), back_inserter(S));
    copy(V2.begin(), V2.end(), back_inserter(S));

    sort(S.begin(), S.end());
    S.erase( unique(S.begin(), S.end()), S.end() );
    for(int i=0; i<N; i++){
      V1[i] = lower_bound(S.begin(), S.end(), V1[i]) - S.begin();
      V2[i] = lower_bound(S.begin(), S.end(), V2[i]) - S.begin();
    }
    return S;
  }
}

#define rep(i, n) for(int i=0; i<(int)n; i++)

int main(){
  int N;cin>>N;
  vector<int> input(N);
  vector<int> in1(N), in2(N);
  rep(i,N)cin>>input[i];
  in1 = input;
  rep(i,N)cin>>in2[i];
  
  vector<int> S = compress(input);

  cout<<"compressed : RawData"<<endl;
  for(int i: input){
    cout<<i<<" : "<<S[i]<<endl;
  }

  S.clear();
  S = compress(in1, in2);

  cout<<"compressed : RawData 1"<<endl;
  rep(i,N)cout<<in1[i]<<" : "<<S[in1[i]]<<endl;
  cout<<"compressed : RawData 2"<<endl;
  rep(i,N)cout<<in2[i]<<" : "<<S[in2[i]]<<endl;
}

/*
//input
7
100 120 120 130 115 115 150
140  80 120 160 120 140 100

//output
compressed : RawData
0 : 100
2 : 120
2 : 120
3 : 130
1 : 115
1 : 115
4 : 150
compressed : RawData 1
1 : 100
3 : 120
3 : 120
4 : 130
2 : 115
2 : 115
6 : 150
compressed : RawData 2
5 : 140
0 : 80
3 : 120
7 : 160
3 : 120
5 : 140
1 : 100

*/