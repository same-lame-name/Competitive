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

int N, diss[(int)1e5 + 5];
pair<int, int> info[(int)1e5 + 5];

int main(){
  FAST_IO
  cin >> N;
  memset(diss, -1, sizeof diss);

  for(int idx = 0, age; idx < N; ++idx){
    cin >> age;
    info[idx] = MP(age, idx);
  }

  sort(info, info + N);
  
  for(int idx = 0, farthest = -1, cur; idx < N; ++idx){
    cur = info[idx].S;
    if(farthest > cur) diss[cur] = farthest - cur - 1;
    else farthest = cur;
  }

  for(int idx = 0; idx < N; ++idx) cout << diss[idx] << " ";
  return 0;
}

