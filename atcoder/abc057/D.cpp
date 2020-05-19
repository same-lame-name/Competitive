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

int N, a, b;
LL choose[55][55], val[55], ways = 0LL;

inline void get(){
  for(int from = 0; from <= N; ++from) choose[from][0] = 1; 

  for(int from = 1; from <= N; ++from){
    for(int k = 1; k <= from; ++k){
      choose[from][k] += choose[from - 1][k] + choose[from - 1][k - 1];
    }
  }

  return;
}

int main(){
  FAST_IO
  cin >> N >> a >> b;
  for(int rep = 0; rep < N; ++rep) cin >> val[rep];

  sort(val, val + N);
  reverse(val, val + N);

  get();

  int pick = 0, total = 0;
  double avg = 0.0;

  for(int rep = 0; rep < a; ++rep) avg += val[rep];
  avg /= a;

  for(int idx = 0; idx < N; ++idx){
    if(val[idx] == val[a - 1]){
      total++;
      if(idx < a) pick++;
    }
  }

  if(pick == a){
    for(int k = a; k <= b; ++k) ways += choose[total][k];
  }else{
    ways += choose[total][pick];
  }

  PRECISION(6);
  cout << avg << '\n';
  cout << ways << '\n';
  return 0;
}
