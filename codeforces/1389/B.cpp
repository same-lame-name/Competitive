
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

// My submissions with array are getting TLE.
// This is strange! I suspect memset is costly.
int testcases, N, k, z, base = -1; 
int rew[(int)1e5 + 5], memo[(int)1e5 + 5][10][2], visited[(int)1e5 + 5][10][2];

int util(int idx, int used, bool can){
  int rem = k - (idx + 2 * used);
  if(rem == 0) return 0;

  int &cur = memo[idx][used][can];
  if(visited[idx][used][can] == base) return cur;
  visited[idx][used][can] = base;

  assert(idx + 1 < N);
  cur = util(idx + 1, used, true) + rew[idx + 1];
  if(used < z && can){
    max_self(cur, util(idx - 1, used + 1, false) + rew[idx - 1]);
  }
  return cur;
}

int main(){
  FAST_IO
  cin >> testcases;

  while(testcases--){
    cin >> N >> k >> z;
    for(int rep = 0; rep < N; ++rep) cin >> rew[rep];
    cout << rew[0] + util(0, 0, false) << '\n';
    base--;
  }
  return 0;
}

