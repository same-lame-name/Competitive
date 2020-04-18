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
  
  int N, best = 0; cin >> N;
  vector<int> candy[2];

  for(int r = 0; r < 2; ++r){
    for(int c = 0; c < N; ++c){
      int x; cin >> x;
      candy[r].PB(x);
    }
  }

  for(int c = 1; c < N; ++c) candy[0][c] += candy[0][c - 1];
  for(int c = N - 2; c >= 0; --c) candy[1][c] += candy[1][c + 1];

  for(int c = 0; c < N; ++c){
    max_self(best, candy[0][c] + candy[1][c]);
  }

  cout << best << "\n";

  return 0;
}