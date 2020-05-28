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

int N;
string in[105];
bool ok;

inline bool isSub(string &a, string &b){
  int _N = SZ(b), M = SZ(a);
  for(int idx = 0; idx <= _N - M; ++idx){
    if(b.substr(idx, M) == a) return true;
  }

  return false;
}

int main(){
  FAST_IO
  ok = true;
  cin >> N;
  for(int rep = 0; rep < N; ++rep) cin >> in[rep];

  sort(in, in + N, [](auto a, auto b){
    return SZ(a) < SZ(b);
  });

  for(int idx = 1; idx < N; ++idx){
    if(!isSub(in[idx - 1], in[idx])){
      ok = false;
      break;
    }
  }

  if(!ok) cout << "NO\n";
  else{
    cout << "YES\n";
    for(int idx = 0; idx < N; ++idx) cout << in[idx] << '\n';
  }
  return 0;
}
