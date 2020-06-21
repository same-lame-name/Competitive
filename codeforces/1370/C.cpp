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

int testcases, N;

bool div(int k){
  for(int d = 3; d * d <= k; d += 2){
    if(k % d == 0) return true;
  }

  return false;
}

void solve(){
  bool winner = 0;
  if(N == 1) winner = 1;
  else if(N == 2 || N & 1) winner = 0;
  else{
    int even = 1;
    while(N % 2 == 0){
      N /= 2;
      even *= 2;
    }

    assert(even >= 2 && (N & 1));
    if(N == 1) winner = 1;
    else if(even > 2) winner = 0;
    else{
      assert(N >= 3 && even == 2);
      if(div(N)) winner = 0;
      else winner = 1;
    }
  }

  if(winner) cout << "FastestFinger\n";
  else cout << "Ashishgup\n";

  return;
}



int main(){
  FAST_IO
  
  cin >> testcases;
  while(testcases--){
    cin >> N;
    solve();
  }

  return 0;
}
