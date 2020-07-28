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

string in;
bool ok[(int)1e5 + 5], good = true;
int N, cnt = 0, del = 0, buffer = 0;
vector<int> moves;
int main(){
  FAST_IO
  cin >> in;
  N = SZ(in);
  memset(ok, true, sizeof ok);
  for(int idx = N - 1; idx >= 0; --idx){
    if(in[idx] == '#') buffer++;
    else if(in[idx] == ')'){
      del++;
      ok[idx] = false;
    }else if(del){
      ok[idx] = false;
      del--;
    }
  }

  if(del) good = false;

  for(int idx = 0; idx < N; ++idx){
    if(in[idx] == '#'){
      assert(buffer);
      if(!cnt){
        good = false;
        break;
      }

      if(--buffer == 0){
        moves.PB(cnt);
        cnt = 0;
      }else{
        moves.PB(1);
        cnt--;
      }

    }else cnt += ok[idx];
  }
    
  if(cnt) good = false;
  if(!good) cout << "-1\n";
  else{
    assert(del == 0);
    for(int ele : moves) cout << ele << '\n';
  }
  return 0;
}

