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

int N, ben[70];
LL k, answer = 0LL, value = 0LL, num[(int)1e5 + 7];
bool lesser = false;

int main(){
  FAST_IO
  cin >> N >> k;
  for(int rep = 0; rep < N; ++rep) cin >> num[rep];

  for(int pos = 60; pos >= 0; --pos){
    for(int idx = 0; idx < N; ++idx){
      if((num[idx] & (1LL << pos))) ben[pos]--;
      else ben[pos]++;
    }
  }

  for(int pos = 60; pos >= 0; --pos){
    if(ben[pos] >= 0){
      if(k & (1LL << pos)){
        answer |= (1LL << pos);
      }else if(lesser) answer |= (1LL << pos);
    }else{
      if(k & (1LL << pos)) lesser = true;
      answer |= (0LL << pos);
    }
  }

  for(int idx = 0; idx < N; ++idx){
    value += answer ^ num[idx];
  }

  cout << value << '\n';
  return 0;
}
