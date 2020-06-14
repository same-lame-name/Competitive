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

int testcases, N, extreme, num[(int)1e5 + 7], opt[(int)1e5 + 7];

bool sharp(int r){
  assert(r > 0 && r < N - 1);
  return (num[r] > num[r - 1]) ^ (num[r] < num[r + 1]);
}

void solve(){
  extreme = 0;
  for(int rep = 0; rep < N; ++rep){
    if(rep == 0 || rep == N - 1 || sharp(rep)){
      opt[extreme] = num[rep];
      extreme++;
    }
  }
  
  cout << extreme << '\n';
  for(int rep = 0; rep < extreme; ++rep) cout << opt[rep] << " ";
  cout << '\n';

  return;
}
  

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N;
    for(int rep = 0; rep < N; ++rep) cin >> num[rep];
    solve();
  }
  return 0;
}
