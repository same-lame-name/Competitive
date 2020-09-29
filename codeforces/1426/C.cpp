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

int testcases, N;

void solve(){
  int bef = sqrt(N), aft = sqrt(N) + 1;
  int first = (N - bef) / bef + ((N - bef) % bef > 0) + bef - 1;
  int second = (N - aft) / aft + ((N - aft) % aft > 0) + aft - 1;
  cout << min(first, second) << '\n';
  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N;
    solve();
  }
  return 0;
}

