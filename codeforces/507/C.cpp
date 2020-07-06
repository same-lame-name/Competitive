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

int H, h = 0;
LL n, visit = 0, mid, l, r;
bool turn = true;

int main(){
  FAST_IO
  cin >> H >> n;
  l = 1, r = (1LL << H);

  while(h < H){
    mid = (l + r) >> 1;
    if(n > mid){
      if(turn) visit += (1LL << (H - h));
      else visit += 1;

      turn = true;
      l = mid + 1;
    }else{
      if(turn) visit += 1;
      else visit += (1LL << (H - h));

      turn = false;
      r = mid;
    }

    h++;
  }

  assert(l == n && r == n);
  cout << visit << '\n';
  return 0;
}

