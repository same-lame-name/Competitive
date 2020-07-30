
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

int testcases, N, k, z, rew[(int)1e5 + 5];// memo[(int)1e5 + 5][10][2];
vector<vector<vector<int>>> memo;

int util(int idx, int used, bool can){
  int rem = k - (idx + 2 * used);
  if(rem == 0) return 0;

  int &cur = memo[idx][used][can];
  if(cur != -1) return cur;

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
    memo = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(10, vector<int>(2, -1)));
//    memset(memo, -1, sizeof memo);
    for(int rep = 0; rep < N; ++rep) cin >> rew[rep];
    cout << rew[0] + util(0, 0, false) << '\n';
  }
  return 0;
}

