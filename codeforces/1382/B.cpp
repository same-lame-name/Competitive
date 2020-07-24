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
bool even, ones;

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N;
    //even stores the parity of number of 1's in prefix in [0, N - 2].
    even = true, ones = true;

    for(int idx = 0, x; idx < N; ++idx){
      cin >> x;
      if(idx == N - 1) continue;

      if(x == 1 && ones) even = !even;
      else ones = false;
    }

    if(even) cout << "First\n";
    else cout << "Second\n";
  }
  return 0;
}

