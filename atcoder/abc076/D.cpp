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

int N;
double v[105], t[105], x[105], area;

int main(){
  FAST_IO

  cin >> N;

  area = 0;

  for(int rep = 0; rep < N; ++rep) cin >> t[rep];
  for(int rep = 0; rep < N; ++rep) cin >> v[rep];

  for(int rep = 1; rep < N; ++rep){
    x[rep] = min(v[rep - 1], v[rep]);
  }

  for(int rep = 1; rep < N; ++rep){
    min_self(x[rep], x[rep - 1] + t[rep - 1]);
  }

  for(int rep = N - 1; rep >= 1; --rep){
    min_self(x[rep], x[rep + 1] + t[rep]);
  }

  for(int i = 0; i < N; ++i){
    double d = t[i] - (v[i] - x[i]) - (v[i] - x[i + 1]);
    double b = max(x[i], x[i + 1]);
    double f = min(x[i], x[i + 1]);

    if(d >= 0){
      area += t[i] * v[i];
      area -= (v[i] - b) * (v[i] - b) / 2.0;
      area -= (v[i] - f) * (v[i] - f) / 2.0;
    }else{
      area += t[i] * f;
      area += t[i] * t[i] / 2.0;
      area -= (f + t[i] - b) * (f + t[i] - b) / 4.0;
    }
  }
      
  PRECISION(3);
  cout << area << '\n';
  return 0;
}
