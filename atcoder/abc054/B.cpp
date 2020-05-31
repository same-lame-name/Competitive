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

int N, M;
string A[55], B[55];

bool check(int row, int col){
  for(int r = 0; r < M; ++r){
    for(int c = 0; c < M; ++c){
      if(B[r][c] != A[row + r][col + c]) return false;
    }
  }

  return true;
}

inline bool solve(){

  for(int r = 0; N - r >= M; ++r){
    for(int c = 0; N - c >= M; ++c){
      if(check(r, c)) return true;
    }
  }

  return false;
}

int main(){
  FAST_IO
  cin >> N >> M;
  
  for(int r = 0; r < N; ++r) cin >> A[r];
  for(int r = 0; r < M; ++r) cin >> B[r];

  if(solve()) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
