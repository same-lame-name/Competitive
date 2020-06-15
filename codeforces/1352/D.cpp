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

int testcases, N, a, b, moves;
int rew[1005];

void solve(){
  a = b = moves = 0;
  int l = 0, r = N - 1, lasta = 0, lastb = 0;

  while(l <= r){
    if(moves & 1){
//      cout << "bobs move   \n";
      int cur = 0;
      while(l <= r && cur <= lasta){
        cur += rew[r];
        r--;
      }

      b += cur;
      lastb = cur;
    }else{
//      cout << "alices move  \n";
      int cur = 0;
      while(l <= r && cur <= lastb){
        cur += rew[l];
        l++;
      }

      a += cur;
      lasta = cur;
    }

    moves++;
  }

  cout << moves << " " << a << " " << b << '\n';
  return;
}

  

int main(){
  FAST_IO

  cin >> testcases;
  while(testcases--){
    cin >> N;
    for(int rep = 0; rep < N; ++rep) cin >> rew[rep];
    solve();
  }

  return 0;
}
