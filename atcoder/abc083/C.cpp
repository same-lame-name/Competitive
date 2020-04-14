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



int main(){
  FAST_IO  
  
  LL a, b; cin >> a >> b;
  
  int min = 1, max = 65, possible = -1;

  auto ok = [&](int len){
    LL factor = (1LL << (len - 1));
    if((__int128)a * factor <= b) return true;
    return false;
  };

  while(min <= max){
    int mid = min + (max - min) / 2;
    if(ok(mid)){
      possible = mid;
      min = mid + 1;
    }else{
      max = mid - 1;
    }
  }

  cout << possible << "\n";

  return 0;
}