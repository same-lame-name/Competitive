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

int N, k;
vector<int> fst, sec, both;

bool check(int x, int y, int z){
  if(x == SZ(fst)) return false;
  if(y == SZ(sec)) return false;
  if(z == SZ(both)) return true;

  return fst[x] + sec[y] <= both[z];
}

void solve(){
  int cost = 0;
  for(int rep = 0, x = 0, y = 0, z = 0; rep < k; ++rep){
   if(check(x, y, z)){
      cost += fst[x++] + sec[y++];
    }else{
      cost += both[z++];
    }
  }

  cout << cost << '\n';
  return;
}

int main(){
  FAST_IO
  cin >> N >> k;
  for(int rep = 0, a, b, t; rep < N; ++rep){
    cin >> t >> a >> b;
    if(a > 0 && b > 0) both.PB(t);
    else if(a > 0) fst.PB(t);
    else if(b > 0) sec.PB(t);
  }

  if(min(SZ(fst), SZ(sec)) + SZ(both) < k){
    cout << "-1\n";
    return 0;
  }

  sort(ALL(fst));
  sort(ALL(sec));
  sort(ALL(both));
  solve();
  return 0;
}

