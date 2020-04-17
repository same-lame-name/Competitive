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
  
  int N, t = 0, x = 0, y = 0; cin >> N;

  for(int rep = 0; rep < N; ++rep){
    int t1, x1, y1; cin >> t1 >> x1 >> y1;
    int d = abs(x1 -x) + abs(y1 - y);
    int delt = t1 - t;
    if(d > delt || (delt - d) & 1){
      cout << "No\n";
      return 0;
    }
    t = t1;
    x = x1;
    y = y1;
  }

  cout << "Yes\n";


  return 0;
}