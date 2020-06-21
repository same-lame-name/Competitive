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
vector<pair<int, int>> q;

int main(){
  FAST_IO
  cin >> N >> M;
  q.resize(M);
  for(auto &ele : q){
    cin >> ele.F >> ele.S;
  }

  sort(ALL(q));

  int left = 0, right = 0, cnt = 0;
  for(auto &ele : q){
    int f = ele.F, t = ele.S; 
//    cout << f << " & " << t << '\n';
    if(f < right){
      max_self(left, f);
      min_self(right, t);
    }else{
      cnt++;
      left = f;
      right = t;
    }
  }

  cout << cnt << '\n';
  return 0;
}
