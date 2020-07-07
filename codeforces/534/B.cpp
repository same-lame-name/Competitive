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

int i, f, t, d, total = 0, most[105];

int main(){
  FAST_IO
  cin >> i >> f >> t >> d;
  most[0] = i;
  most[t - 1] = f;
  for(int rep = 1, lst = i; rep < t - 1; ++rep){
    most[rep] = lst + d;
    lst = most[rep];
  }

  for(int rep = t - 2, lst = f; rep > 0; --rep){
    min_self(most[rep], lst + d);
    lst = most[rep];
  }
  
  for(int rep = 0; rep < t; ++rep) total += most[rep];
  cout << total;
  return 0;
}

