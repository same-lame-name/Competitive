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

const int M = 55555;
bool isPrime[M + 5];
vector<int> in;

inline void sieve(){
  isPrime[0] = isPrime[1] = false;

  for(int prime = 2; prime * prime < M; ++prime){
    if(!isPrime[prime]) continue;

    for(int composite = prime * prime; composite < M; composite += prime){
      isPrime[composite] = false;
    }
  }

  for(int prime = 2; prime < M; ++prime){
    if(prime % 5 != 1) continue;
    if(isPrime[prime]) in.PB(prime);
  }

  return;
}
    

int main(){
  FAST_IO
  int N; cin >> N;
  memset(isPrime, true, sizeof isPrime);

  sieve();

  for(int rep = 0; rep < N; ++rep) cout << in[rep] << " ";

  return 0;
}
