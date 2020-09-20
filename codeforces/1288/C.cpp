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

int N, M;
LL memo[1005][15];

LL util(int diff, int placed){
  assert(diff >= 0);
  if(placed == M) return 1;

  LL &count = memo[diff][placed];
  if(count != -1) return count;

  count = 0;
  for(int dec = 0; dec <= diff; ++dec){
    count = (count + (dec + 1) * util(diff - dec, placed + 1)) % INF;
  }

  return count;
}


int main(){
  FAST_IO
  cin >> N >> M;
  memset(memo, -1, sizeof memo);
  cout << util(N - 1, 0);
  
  return 0;
}

