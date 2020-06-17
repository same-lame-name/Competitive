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

int testcases, N, k, opt;
string sat;
bool avail[(int)2e5 + 7];

void solve(){
  memset(avail, true, sizeof avail);
  opt = 0;

  cin >> sat;
  
  int last = -INF;
  for(int pos = 0; pos < N; ++pos){
    if(sat[pos] > '0'){
      last = pos;
      avail[pos] = false;
    }
    else if(pos - last <= k) avail[pos] = false;
  }

  last = INF;
  for(int pos = N - 1; pos >= 0; --pos){
    if(sat[pos] > '0'){
      last = pos;
      avail[pos] = false;
    }else if(last - pos <= k) avail[pos] = false;
  }

  last = 0;
  for(int idx = 0; idx < N; ++idx){
    if(avail[idx]) last++;
    else{
      opt += (last + k) / (k + 1);
      last = 0;
    }
  }

  if(last) opt += (last + k) / (k + 1);
  cout << opt << '\n';

  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> k;
    solve();
  }
  return 0;
}
