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

int N, height[(int)1e5 + 5], opt[(int)1e5 + 5];

int main(){
  FAST_IO  
  cin >> N;
  for(int rep = 0; rep < N; ++rep) cin >> height[rep];
  for(int rep = 0; rep < N; ++rep) opt[rep] = INF;

  opt[0] = 0;
  for(int idx = 0; idx < N - 1; ++idx){
    for(int s : {1, 2}){
      min_self(opt[idx + s], opt[idx] + abs(height[idx + s] - height[idx]));
    }
  }

  cout << opt[N - 1] << '\n';
  return 0;
}