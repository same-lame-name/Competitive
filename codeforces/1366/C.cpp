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

int testcases, N, M, len, total;
pair<int, int> cnt[65];

void solve(){
  total = 0;
  len = N + M - 1;
  for(int pos = 0; pos < len; ++pos) cnt[pos] = MP(0, 0);

  for(int r = 0; r < N; ++r){
    for(int c = 0, x; c < M; ++c){
      cin >> x;
      if(x) cnt[r + c].F++;
      else cnt[r + c].S++;
    }
  }
  
  for(int rep = 0, l = 0, r = len - 1, o, z; rep < len / 2; ++rep){
    o = cnt[l].F + cnt[r].F;
    z = cnt[l].S + cnt[r].S;
    total += min(o, z);
    l++;
    r--;
  }
    
  cout << total << '\n';
  return;
}


      

int main(){
  FAST_IO
  cin >> testcases;

  while(testcases--){
    cin >> N >> M;
    solve();
  }

  return 0;
}
