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

LL util;
int N;
bool isPrime[(int)1e6 + 5];

inline bool isSquare(LL x){
  return (LL)sqrt(x) * sqrt(x) == x;
}

int main(){
  FAST_IO
  cin >> N;

  memset(isPrime, true, sizeof isPrime);
  for(LL prime = 2; prime * prime <= 1e6; ++prime){
    if(!isPrime[prime]) continue;

    for(LL comp = prime * prime; comp <= 1e6; comp += prime){
      isPrime[comp] = false;
    }
  }

  for(int idx = 0; idx < N; ++idx){
    cin >> util;
    if(util > 1 && isSquare(util) && isPrime[(LL)sqrt(util)]){
      cout << "YES\n";
    }else cout << "NO\n";
  }

  return 0;
}
