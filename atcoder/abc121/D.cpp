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

LL a, b;

LL get(LL x){
  LL ones = (x + 1) / 2;
  LL result = 0;
  if(ones & 1) result = 1;
  
  if(x % 2 == 0) result ^= x;

  return result;
}

int main(){
  FAST_IO
  cin >> a >> b;
  LL A = get(a - 1);
  LL B = get(b);

  cout << (A ^ B) << '\n';
  return 0;
}
