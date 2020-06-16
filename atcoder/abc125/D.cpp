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
//const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);
const LL INF = 1e18;

int N, num[(int)1e5 + 7];
LL memo[(int)1e5 + 7][2];

int main(){
  FAST_IO
  memset(memo, -1, sizeof memo);
  cin >> N;
  for(int idx = 0; idx < N; ++idx) cin >> num[idx];

  memo[N - 1][0] = num[N - 1];
  memo[N - 1][1] = -1LL * num[N - 1];

  for(int idx = N - 2; idx >= 0; --idx){
    memo[idx][0] = max(num[idx] + memo[idx + 1][0],
                       num[idx] * -1LL + memo[idx + 1][1]);

    memo[idx][1] = max(num[idx] * -1LL + memo[idx + 1][0],
                       num[idx] + memo[idx + 1][1]);
  }

  cout << memo[0][0] << '\n';
  return 0;
}
