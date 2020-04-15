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
 
  const int LIM = 1e5;
  int pref[LIM + 5];
  bool isPrime[LIM + 5];
  memset(isPrime, true, sizeof isPrime);
  memset(pref, 0, sizeof pref);

  isPrime[0] = isPrime[1] = false;

  for(int prime = 2; prime * prime <= LIM; ++prime){
    if(!isPrime[prime]) continue;
    for(int composite = prime * prime; composite <= LIM; composite += prime){
      isPrime[composite] = false;
    }
  }

  for(int num = 1; num <= LIM; ++num){
    pref[num] = pref[num - 1];
    if(isPrime[num] && isPrime[(num + 1) / 2]) pref[num]++;
  }

  int N; cin >> N;

  while(N--){
    int left, right; cin >> left >> right;
    cout << pref[right] - pref[left - 1] << "\n";
  }


  return 0;
}