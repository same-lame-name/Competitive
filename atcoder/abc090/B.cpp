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

template<class T> void max_self(T & a, const T & b) { if(a < b) a = b; }
template<class T> void min_self(T & a, const T & b) { if(a > b) a = b; }
typedef long long LL;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);


int main(){
  FAST_IO  

  int cnt = 0;
  string from, till, util;
  cin >> from >> till;
  util = from;

  for(int f = 0; f <= 9; ++f){
    for(int s = 0; s <= 9; ++s){
      for(int m = 0; m <= 9; ++m){
        util[0] = util[4] = f + '0';
        util[1] = util[3] = s + '0';
        util[2] = m + '0';
        if(util >= from && util <= till) cnt++;
      }
    }
  }

  cout << cnt << "\n";
  return 0;
}