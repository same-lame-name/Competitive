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

int testcases, N, k, num[(int)2e5 + 7], cost[(int)4e5 + 5];

void solve(){
  int opt = INF;
  for(int rep = 0; rep < N; ++rep) cin >> num[rep];

  memset(cost, 0, sizeof cost);

  for(int rep = 0, dis; rep < N / 2; ++rep){
    dis = 0;
    cost[1] += 2, cost[2 * k + 1] -= 2;
    int a = num[rep], b = num[N - 1 - rep];
    if(a > k) dis++;
    if(b > k) dis++;

//    cout << rep << " there is " << dis << " much discrepancy \n";

    if(dis < 2){
      int least = min(a + 1, b + 1);
      int most = max(a + k, b + k);
//      cout << least << " till " << most << "\n";
      cost[least] -= 1;
      cost[most + 1] += 1;
    }

    if(dis < 1){
      int least = a + b;
      int most = a + b;
      cost[least] -= 1;
      cost[most + 1] += 1;
    }
  }

  for(int x = 2; x <= 2 * k; ++x){
    cost[x] += cost[x - 1];
    min_self(opt, cost[x]);
  }

  cout << opt << '\n';
}


    

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> k;
    solve();
  }
  return 0;
}
