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

int N, M, fst, sec, optf, opts, optdiff;
map<int, pair<int, int>> cnt;

int main(){
  FAST_IO
  cin >> N;
  for(int rep = 0, x; rep < N; ++rep){
    cin >> x;
    cnt[x].F++;
  }
  cin >> M;
  for(int rep = 0, x; rep < M; ++rep){
    cin >> x;
    cnt[x].S++;
  }
  
  optf = fst = N * 3, opts = sec =  M * 3;
  optdiff = optf - opts;

  for(auto &[k, v] : cnt){
    fst -= v.F;
    sec -= v.S;

    if(max_self(optdiff, fst - sec)){
      optf = fst;
      opts = sec;
    }
  }

  cout << optf << ":" << opts << '\n';
  return 0;
}

