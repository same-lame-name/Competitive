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

int N, total = 0;
vector<int> both, fst, sec, none;
string util;

int main(){
  FAST_IO
  cin >> N;
  for(int rep = 0, x; rep < N; ++rep){
    cin >> util >> x;
    if(util == "10") fst.PB(x);
    else if(util == "01") sec.PB(x);
    else if(util == "11") both.PB(x);
    else none.PB(x);
  }

  if(SZ(both) + min(SZ(fst), SZ(sec)) == 0){
    cout << "0\n";
    return 0;
  }

  for(int ele : both) total += ele;
  sort(ALLR(fst));
  sort(ALLR(sec));

  for(int idx = 0; idx < max(SZ(fst), SZ(sec)); ++idx){
    if(idx >= SZ(fst)) none.PB(sec[idx]);
    else if(idx >= SZ(sec)) none.PB(fst[idx]);
    else total += sec[idx] + fst[idx];
  }

  sort(ALLR(none));
  for(int rep = 0; rep < min(SZ(both), SZ(none)); ++rep) total += none[rep];
  cout << total << '\n';
  return 0;
}

