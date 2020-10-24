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

int testcases, N, odd;

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N;
    if(N <= 3){
      cout << "-1\n";
      continue;
    }
    odd = N - !(N & 1); 
    for(int x = odd; x > 0; x -= 2) cout << x << " ";
    cout << "4 2 ";
    for(int x = 6; x <= N; x += 2) cout << x << " ";
    cout << '\n';
  }
  return 0;
}

