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

LL testcases, N, num[(int)2e5 + 7], opt;

LL get(vector<LL>& a){
  LL pre = 0, sub = 0;
  for(LL ele : a){
    pre = max(ele, pre + ele);
    max_self(sub, pre);
  }

//  cout << sub << '\n';

  return sub;
}

void solve(){
  vector<LL> even, odd;
  opt = 0;
  for(int idx = 0; idx < N; idx += 2){
    if(idx + 1 < N){
      even.PB(num[idx + 1] - num[idx]);
    }
    opt += num[idx];
  }

//  cout << opt << '\n';

  for(int idx = 1; idx < N; idx += 2){
    if(idx + 1 < N){
      odd.PB(num[idx] - num[idx + 1]);
    }
  }

//  for(LL ele : even) cout << ele << " ";
//  cout << '\n';
//  for(LL ele : odd) cout << ele << " ";
//  cout << '\n';

  cout << opt + max(get(even), get(odd)) << '\n';
}
  
int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N;
    for(int rep = 0; rep < N; ++rep) cin >> num[rep];
    solve();
  }
  return 0;
}
