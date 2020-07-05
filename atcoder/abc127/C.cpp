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

int cnt[(int)1e5 + 5], N, m, total = 0;

int main(){
  FAST_IO
  cin >> N >> m;
  for(int rep = 0, l, r; rep < m; ++rep){
    cin >> l >> r;
    cnt[l]++;
    cnt[r + 1]--;
  }

  for(int pos = 1; pos <= N; ++pos){
    cnt[pos] += cnt[pos - 1];
    if(cnt[pos] == m) total++;
  }

  cout << total << '\n';
  return 0;
}

