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

LL H, n;

LL util(bool moveright, int h, LL l, LL r){
  if(h == H){
    assert(l == r && l == n);
    return 0;
  }

  LL ret = 1, mid = (l + r) / 2;
  bool right = (n > mid);

  if(moveright ^ right) ret += (1LL << (H - h)) - 1;

  if(right) return ret + util(false, h + 1, mid + 1, r);
  else return ret + util(true, h + 1, l, mid);

}

int main(){
  FAST_IO
  cin >> H >> n;

  cout << util(false, 0, 1, (1LL << H));
  return 0;
}

