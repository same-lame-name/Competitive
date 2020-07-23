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

int testcases, N, M, match;
bool present[1005];

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    memset(present, false, sizeof present);
    match = 0;

    cin >> N >> M;
    for(int rep = 0, x; rep < N; ++rep){
      cin >> x;
      present[x] = true;
    }

    for(int rep = 0, x; rep < M; ++rep){
      cin >> x;
      if(present[x]) match = x;
    }

    if(match > 0){
      cout << "YES\n1 " << match << '\n';
    }else cout << "NO\n";
  }

  return 0;
}

