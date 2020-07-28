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
LL cnt = 1, N, a = 0;

int main(){
  FAST_IO
  cin >> in;
  N = SZ(in);

  for(int idx = 0; idx < N; ++idx){
    if(in[idx] == 'b'){
      cnt = (cnt * (a + 1)) % INF;
      a = 0;
    }else if(in[idx] == 'a') a++;
  }
  
  cnt = (cnt * (a + 1)) % INF;
  cnt--;
  if(cnt < 0) cnt += INF;
  cout << cnt << '\n';
  return 0;
}

