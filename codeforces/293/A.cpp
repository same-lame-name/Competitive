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

int N, both = 0, me = 0, him = 0, diff = 0, turn = 0, no_conflict;
string f, s;

int main(){
  FAST_IO
  cin >> N >> f >> s;
  for(int idx = 0; idx < 2 * N; ++idx){
    if(f[idx] == '1' && s[idx] == '1') both++;
    else if(f[idx] == '1') me++;
    else if(s[idx] == '1') him++;
  }

  if(both & 1){
    turn = !turn;
    diff += 1;
  }

  no_conflict = min(me, him);
  me -= no_conflict;
  him -= no_conflict;

  if(me){
    if(turn == 0) diff += (me + 1) / 2;
    else diff += me / 2;
  }else if(him){
    if(turn == 1) diff -= (him + 1) / 2;
    else diff -= him / 2;
  }

  if(diff > 0) cout << "First\n";
  else if(diff < 0) cout << "Second\n";
  else cout << "Draw\n";

  return 0;
}

