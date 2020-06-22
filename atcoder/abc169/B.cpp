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

 
int main(){
  FAST_IO
  int N;
  cin >> N;

  vector<LL> num(N);
  for(LL &ele : num) cin >> ele;
  sort(ALL(num));

  __int128 product = 1;
  for(LL ele : num){
    product = product * ele;
    if(product > (LL)1e18){
      cout << "-1\n";
      return 0;
    }
  }

  cout << (LL)product << '\n';
  return 0;
}
