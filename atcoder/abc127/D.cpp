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

int N, M;
LL total = 0;
vector<int> num;
vector<pair<int, int>> avail;

void solve(){
  int idx = 0;
  for(auto &ele : avail){
    for(int rep = 0; rep < ele.S; ++rep){
      if(num[idx] >= ele.F) break;
      num[idx] = ele.F;
      idx++;
      if(idx == N) goto out;
    }
  }

  out:
  for(int &ele : num) total += ele;
  cout << total << '\n';
  return;
}
    
int main(){
  FAST_IO
  cin >> N >> M;
  num.resize(N);
  avail.resize(M);
  for(int &ele : num) cin >> ele;
  for(auto &ele : avail) cin >> ele.S >> ele.F;

  sort(ALL(num));
  sort(ALLR(avail));

  solve();
  return 0;
}

