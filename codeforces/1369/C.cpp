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

int testcases, N, k;
vector<int> avail, w;

void solve(){
  LL total = 0;
  sort(ALLR(avail));
  sort(ALL(w));

  int fst = 0, lst = k - 1;
  for(int req : w){
    assert(fst < k);
    total += avail[fst];
    if(req == 1){
      total += avail[fst];
    }else{
      lst += req - 1;
      total += avail[lst];
    }

    fst++;
  }

  cout << total << '\n';
  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> k;
    avail.resize(N);
    w.resize(k);
    for(int &ele : avail) cin >> ele;
    for(int &ele : w) cin >> ele;
    solve();
  }
  return 0;
}
