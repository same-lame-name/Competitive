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
LL k;
string in;
queue<int> zeros;

void solve(){
  assert(zeros.empty());

  for(int idx = 0, front = 0; idx < N; ++idx){
    if(in[idx] == '1') continue;
    if(idx - front <= k){
      zeros.push(front);
      k -= (idx - front);
      front++;
    }else{
      zeros.push(idx - k);
      k -= k;
    }
  }
  
  for(int idx = 0; idx < N; ++idx){
    if(!zeros.empty() && idx == zeros.front()){
      zeros.pop();
      cout << 0;
    }
    else cout << 1;
  }

  cout << '\n';

  return;
}
 
int main(){
  FAST_IO

  cin >> testcases;
  while(testcases--){
    cin >> N >> k >> in;
    solve();
  }

  return 0;
}

