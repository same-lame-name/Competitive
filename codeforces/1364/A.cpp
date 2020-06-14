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

int testcases, N, x, total, num[(int)1e5 + 7];

void solve(){
  total = 0; 
  for(int rep = 0; rep < N; ++rep) total += num[rep];
  if(total % x){
    cout << N << '\n';
    return;
  }

  int left = 0, right = N - 1, cnt = INF, cur = 0;
  while(left < N && num[left] % x == 0){
    left++;
    cur++;
  }

  min_self(cnt, cur);
  cur = 0;

  while(right >= 0 && num[right] % x == 0){
    right--;
    cur++;
  }

  min_self(cnt, cur);

  cout << N - cnt - 1 << '\n';
  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> x;
    for(int rep = 0; rep < N; ++rep) cin >> num[rep];
    solve();
  }
  return 0;
}
