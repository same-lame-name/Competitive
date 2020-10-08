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

LL N, pref = 0, cnt = 0, x;
set<LL> allPref;

int main(){
  FAST_IO
  cin >> N;
  allPref.insert(0);
  for(int rep = 0; rep < N; ++rep){
    cin >> x;
    pref += x;
    if(allPref.count(pref)){
      cnt++;
      allPref.clear();
      pref = x;
      allPref.insert(x);
      allPref.insert(0);
    }
    else{
      allPref.insert(pref);
    }
  }
  
  cout << cnt;
  return 0;
}

