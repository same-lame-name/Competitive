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

int testcases, N, k;

void solve(){
  int rem = N % k, base = N / k;
  if(base == 0){
    cout << "NO\n";
    return;
  }

  if(rem & 1){
    if(k % 2 == 0 || base == 1){
      cout << "NO\n";
      return;
    }

    cout << "YES\n";
    for(int rep = 0; rep < rem; ++rep) cout << base + 1 << " ";
    for(int rep = 0; rep < k - rem; ++rep){
      if(rep & 1) cout << base + 1 << " ";
      else cout << base - 1 << " ";
    }
    cout << '\n';

    return;
  }

  cout << "YES\n";
  for(int rep = 0; rep < rem / 2; ++rep) cout << base + 2 << " ";
  for(int rep = 0; rep < k - rem / 2; ++rep) cout << base << " ";
  cout << '\n';

  return;
}

int main(){
  FAST_IO
  cin >> testcases;

  while(testcases--){
    cin >> N >> k;
    solve();
  }

  return 0;
}
