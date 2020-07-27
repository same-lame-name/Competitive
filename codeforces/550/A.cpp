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

string in, util;
int occ[2], N;
bool possible = false;

int main(){
  FAST_IO
  cin >> in;
  N = SZ(in);
  occ[0] = occ[1] = N;
  for(int idx = 0; idx < SZ(in) - 1; ++idx){
    util = in.substr(idx, 2);
    if(util == "AB"){
      if(idx - occ[1] > 1) possible = true;
      min_self(occ[0], idx);
    }else if(util == "BA"){
      if(idx - occ[0] > 1) possible = true;
      min_self(occ[1], idx);
    }
  }


  if(possible) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}

