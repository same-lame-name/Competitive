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

int testcases, N, dis, even, odd, evenr, oddr;

void solve(){
//  cout << N << '\n';
  even = odd = dis = 0;
  evenr = N / 2 + (N & 1), oddr = N - evenr;
  
  for(int rep = 0, x; rep < N; ++rep){
    cin >> x;
    if(x & 1) odd++;
    else even++;
    if((x & 1) != (rep & 1)) dis++;
  }

  if(even != evenr){
    cout << "-1\n";
    return;
  }

//  cout << evenr << " " << oddr << " " << even << " " << odd << " " << dis << '\n';

  assert(oddr == odd && (dis % 2 ==0));
  cout << dis / 2 << '\n';
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
