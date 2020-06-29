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

int testcases, N;

void solve(){
  int two = 0, three = 0;

  while(N % 2 == 0){
    N /= 2;
    two++;
  }

  while(N % 3 == 0){
    N /= 3;
    three++;
  }

  if(N > 1 || two > three){
    cout << "-1\n";
    return;
  }
  
  assert(two <= three);
  cout << two + 2 * (three - two) << '\n'; 

  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N;
    solve();
  }
  return 0;
}

