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

int N, nxt[(int)2e5 + 7][30], opt[(int)2e5 + 7];
string in;

int main(){
  FAST_IO
  cin >> in;
  N = SZ(in);
  for(int c = 0; c < 26; ++c) nxt[N][c] = N;

  for(int idx = N - 1; idx >= 0; --idx){
    for(int c = 0; c < 26; ++c){
      if(in[idx] == char(c + 'a')) nxt[idx][c] = idx;
      else nxt[idx][c] = nxt[idx + 1][c];
    }
  }

  opt[N] = 1;
  for(int idx = N - 1; idx >= 0; --idx){
    opt[idx] = INF;
    for(int c = 0, match; c < 26; ++c){
      match = nxt[idx][c];
      min_self(opt[idx], opt[match + 1] + 1);
    }
  }
      
  int itr = 0, c;
  while(itr < N + 1){
    for(c = 0; c < 26; ++c){
      int match = nxt[itr][c];
      if(opt[itr] == opt[match + 1] + 1){
        itr = match + 1;
        break;
      }
    }

    assert(c >= 0 && c < 26);
    cout << char('a' + c);
  }

  return 0;
}
