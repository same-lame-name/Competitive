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
//const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);

const LL INF = 1e18;

int N, cost[(int)1e5 + 7];
string in[(int)1e5 + 7];
LL bst, memo[(int)1e5 + 7][2]; 

bool ok(bool revC, bool revP, int idx){
  string prev = in[idx - 1];
  string cur = in[idx];
  if(revP) reverse(ALL(prev));
  if(revC) reverse(ALL(cur));

  return cur >= prev;
}

int main(){
  FAST_IO
  cin >> N;
  for(int rep = 0; rep < N; ++rep) cin >> cost[rep];
  for(int rep = 0; rep < N; ++rep) cin >> in[rep];

  memo[0][0] = 0;
  memo[0][1] = cost[0];

  for(int idx = 1; idx < N; ++idx){
    for(bool cur : {true, false}){
      memo[idx][cur] = INF;
      for(bool prev : {true, false}){
        if(ok(cur, prev, idx)){
          min_self(memo[idx][cur], (LL)cost[idx] * cur + memo[idx - 1][prev]);
        }
      }
    }
  }


  bst = min(memo[N - 1][0], memo[N - 1][1]); 
  cout << (bst < INF ? bst : -1);
  return 0;
}
