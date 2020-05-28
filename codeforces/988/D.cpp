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

int N, num[(int)2e5 + 5], opt[(int)2e5 + 5], bst, back, diff;

inline int solve(int d){
  int util = 0;
  
  for(int idx = 0; idx < N; ++idx){
    opt[idx] = 1;
    auto itr = lower_bound(num, num + N, num[idx] - d);
    int pIdx = distance(num, itr);
    if(*itr == num[idx] - d) opt[idx] += opt[pIdx];

    if(opt[idx] > util){
      util = opt[idx];
      if(util > bst){
        bst = util;
        back = num[idx];
        diff = d;
      }
    }
  }

  return util;
}




int main(){
  FAST_IO
  bst = 0;
  cin >> N;
  for(int idx = 0; idx < N; ++idx) cin >> num[idx];
  sort(num, num + N);

  for(int rep = 0, d; rep <= 30; ++rep){
    d = (1 << rep);
//    cout << d << '\n';
    solve(d);
  }

//  if(!bst){
//    cout << "1\n";
//    cout << num[0];
//    return 0;
//  }

  cout << min(bst, 3) << '\n';
  for(int rep = 0; rep < min(bst, 3); ++rep){
    cout << back << " ";
    back -= diff;
  }

  return 0;
}
