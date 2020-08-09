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

int testcases, N, a, b, c;
string in, moves;


void solve(){
  int score, r = 0, p = 0, s = 0;
  for(char x : in){
    if(x == 'R') r++;
    else if(x == 'P') p++;
    else s++;
  }

  score = min(r, b) + min(p, c) + min(s, a);
  if(2 * score < N) cout << "No\n";
  else{
    cout << "Yes\n";
    moves = string(N, '#');
    for(int idx = 0; idx < N; ++idx){
      if(in[idx] == 'R' && b){
        moves[idx] = 'P';
        b--;
      }else if(in[idx] == 'P' && c){
        moves[idx] = 'S';
        c--;
      }else if(in[idx] == 'S' && a){
        moves[idx] = 'R';
        a--;
      }
    }

    for(char x : moves){
      if(x == '#'){
        if(a){
          cout << 'R';
          a--;
        }else if(b){
          cout << 'P';
          b--;
        }else{
          assert(c > 0);
          cout << 'S';
          c--;
        }
      }else cout << x;
    }
    cout << '\n';
  }
    
  return;
}


  

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> a >> b >> c >> in;
    solve();
  }
  return 0;
}

