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



int main(){
  FAST_IO  
  
  int N, a, b, sum = 0; cin >> N >> a >> b;
  
  auto ok = [&](int n){
    int digit = 0;
    while(n){
      digit += n % 10;
      n /= 10;
    }

    if(digit >= a && digit <= b) return true;
    return false;
  };

  for(int num = 1; num <= N; ++num){
    if(ok(num)) sum += num;
  }

  cout << sum << "\n";


  return 0;
}