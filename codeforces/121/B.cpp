#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define ALLR(X) (X).rbegin(), (X).rend()
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second

using namespace std;
 
template<class T> bool max_self(T & a, const T & b){ 
  return b > a ? a = b, true : false; 
}
template<class T> bool min_self(T & a, const T & b){ 
  return b < a ? a = b, true : false;    
}
typedef long long LL;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);

int N, k;
string in, util;

int main(){
  FAST_IO
  cin >> N >> k >> in;
  for(int idx = 0; idx < N - 1; ++idx){
    if(k == 0) break;

    util = in.substr(idx, 2);
    if(util == "47"){
      if(idx > 0 && in[idx - 1] == '4' && (idx & 1) > 0){
        if(k & 1) in[idx] = '7';
        k = 0;
      }else if(idx + 2 < N && in[idx + 2] == '7' && (idx & 1) == 0){
        if(k & 1) in[idx + 1] = '4';
        k = 0;
      }else if(idx & 1){
        in[idx] = '7';
        k--;
      }
      else{
        in[idx + 1] = '4';
        k--;
      }
    }
  }

  cout << in << '\n'; 
  return 0;
}

