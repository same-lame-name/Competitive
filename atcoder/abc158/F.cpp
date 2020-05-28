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
const int INF = 2e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);

int N, opt[(int)2e5 + 5], MOD = 998244353;
pair<int, int> info[(int)2e5 + 5];
stack<pair<int, int>> nxt;

int main(){
  FAST_IO
  cin >> N;
  for(int rep = 0, x, d; rep < N; ++rep){
    cin >> x >> d;
    info[rep] = MP(x, d);
  }
  sort(info, info + N);

  nxt.push(MP(N, INF));
  opt[N] = 1;

  for(int idx = N - 1, reach, r; idx >= 0; --idx){
    reach = info[idx].F + info[idx].S;
    while(nxt.top().S < reach) nxt.pop();

    r = nxt.top().F;
    opt[idx] = (opt[idx + 1] + opt[r]) % MOD;
    nxt.push(MP(idx, info[idx].F));
  }

  cout << opt[0];
  return 0;
}
