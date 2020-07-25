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

int N, opt[55], rew[55], suff[55];

int main(){
  FAST_IO
  cin >> N;
  for(int rep = 0; rep < N; ++rep) cin >> rew[rep];
  for(int idx = N - 1; idx >= 0; --idx) suff[idx] = rew[idx] + suff[idx + 1];

  for(int idx = N - 1; idx >= 0; --idx){
    opt[idx] = opt[idx + 1];
    max_self(opt[idx], rew[idx] + suff[idx + 1] - opt[idx + 1]);
  }

  cout << suff[0] - opt[0] << " " << opt[0] << '\n';
  return 0;
}

