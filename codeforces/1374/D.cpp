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

int testcases, N, k;
map<int, int> cnt;
LL req;

void solve(){
  req = 0;
  cnt.clear();

  for(int rep = 0, x; rep < N; ++rep){
    cin >> x;
    if(x % k == 0) continue;
    cnt[k - x % k]++;
  }

  for(auto ele : cnt){
    max_self(req, (LL)k * (ele.S - 1) + (LL)ele.F);
  }

  if(req > 0) req++;
  cout << req << '\n';
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> k;
    solve();
  }
  return 0;
}

