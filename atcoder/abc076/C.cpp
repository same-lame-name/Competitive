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

string a, b;

inline void solve(){
  int N = SZ(a), M = SZ(b), repIdx = -1;
  
  auto check = [&](int idx){
    if(N - idx < M) return false;

    for(int rep = 0; rep < M; ++rep){
      if(a[idx + rep] == '?') continue;
      if(a[idx + rep] != b[rep]) return false;
    }
    
    return true;
  };

  for(int idx = 0; idx < N; ++idx){
    if(check(idx)) repIdx = idx;
  }

  if(repIdx == -1) cout << "UNRESTORABLE\n";
  else{
    for(int idx = 0; idx < N; ++idx){
      if(idx >= repIdx && idx <= repIdx + M - 1){
        cout << b[idx - repIdx];
        continue;
      }

      if(a[idx] == '?') cout << 'a';
      else cout << a[idx];
    }
  }
}

  


int main(){
  FAST_IO
  cin >> a >> b;

  solve();

  return 0;
}
