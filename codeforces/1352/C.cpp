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

LL testcases, n, k;

void solve(){
  cout << ((k / (n - 1)) * n - 1) + (k % (n - 1) ? 1 + k % (n - 1) : 0) << '\n';
  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> n >> k;
    solve();
  }

  return 0;
}
