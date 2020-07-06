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

int N, t;
string a, b, res;
bool done[(int)1e5 + 5];

char get(int idx){
  assert(idx >= 0 && idx < N);

  for(char c = 'a'; c <= 'z'; ++c){
    if(a[idx] != c && b[idx] != c) return c;
  }

  assert(false);
  return '#';
}

void solve(){
  res.resize(N, ' ');
  int req = 2 * (N - t);
  for(int idx = 0; idx < N; ++idx){
    if(a[idx] != b[idx]) continue;
    if(req == 0) break;

    req -= 2;
    done[idx] = true;
    res[idx] = a[idx];
  }

  assert(req >= 0);

  for(int idx = 0, turn = 0; idx < N; ++idx){
    if(done[idx]) continue;
    if(req == 0) break;

    req--;
    if(turn & 1) res[idx] = b[idx];
    else res[idx] = a[idx];

    turn++;
    done[idx] = true;
  }

  for(int idx = 0; idx < N; ++idx){
    if(done[idx]) continue;
    res[idx] = get(idx);
  }

  if(req > 0) cout << "-1\n";
  else cout << res << '\n';

  return;
}

  

int main(){
  FAST_IO
  cin >> N >> t >> a >> b;
  memset(done, false, sizeof done);
  solve();
  return 0;
}

