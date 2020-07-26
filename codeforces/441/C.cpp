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

int N, M, k, r, c, idx;
bool ltr = true;
vector<pair<int, int>> snake;

int main(){
  FAST_IO
  cin >> N >> M >> k;
  for(r = 1, c = 0; r <= N; ++r){

    if(ltr){
      assert(c == 0);
      c++;
      while(c <= M){
        snake.PB(MP(r, c));
        c++;
      }
    }
    else{
      assert(c == M + 1);
      c--;
      while(c >= 1){
        snake.PB(MP(r, c));
        c--;
      }
    }

    ltr = !ltr;
  }

  idx = 0;
  for(int rep = 0; rep < k - 1; ++rep, cout << '\n'){
    cout << 2 << " ";
    for(int itr = 0; itr < 2; ++itr, ++idx) cout << snake[idx].F << " " << snake[idx].S << " ";
  }

  assert(SZ(snake) - idx >= 2 && SZ(snake) - idx == N * M - 2 * (k - 1));
  cout << N * M - 2 * (k - 1) << " ";
  for(;idx < SZ(snake); ++idx) cout << snake[idx].F << " " << snake[idx].S << " ";
  return 0;
}

