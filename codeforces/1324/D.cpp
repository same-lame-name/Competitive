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

int N;
vector<int> diff;

void solve(){
  LL cnt = 0;
  sort(ALL(diff));

  int right = N - 1;
  for(int idx = 0; idx < N; ++idx){
    while(right >= 0 && diff[right] + diff[idx] > 0) right--;
    cnt += min(N - idx - 1, N - right - 1);
  }
    
  cout << cnt << '\n';
  return;
}

int main(){
  FAST_IO
  cin >> N;
  diff.resize(N);
  for(int rep = 0; rep < N; ++rep) cin >> diff[rep];
  for(int rep = 0, x; rep < N; ++rep){
    cin >> x;
    diff[rep] -= x;
  }
  
  solve();

  return 0;
}

