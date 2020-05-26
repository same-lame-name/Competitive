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
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);

set<int> diff, nxt;
int N, num[(int)1e5 + 5], cnt, opt;

inline bool check(int del, int d){
  cnt = abs(del);
  int cur = num[1] + del;
//  if(d == 0 && del == 0) cout << cur << "\n";
  for(int rep = 2, n; rep <= N; ++rep){
    n = cur - d;
//    if(d == 0 && del == 0) cout << n << "\n";
    if(abs(num[rep] - n) > 1) return false;
    cnt += abs(num[rep] - n);
    cur = n;
  }
//  if(d == 0 && del == 0) cout << "hello\n\n\n";

  return true;
}

int main(){
  FAST_IO
  cin >> N;

  cnt = 0;
  opt = INF;
  for(int rep = 1; rep <= N; ++rep) cin >> num[rep];

  if(N == 1){
    cout << 0 << '\n';
    return 0;
  }

  for(int rep = 2, d; rep <= N; ++rep){
    d = num[rep - 1] - num[rep];

    for(int pos = d - 2; pos <= d + 2; ++pos){
//      cout << pos << ' ';
      if(rep == 2 || diff.count(pos)){
        nxt.insert(pos);
      }
    }
//    cout << '\n';

    diff = nxt;
    nxt.clear();
//    for(int ele : diff) cout << ele << " " ;
//    cout << "\n\n\n";
  }

//  for(int ele : diff) cout << ele << '\n';

  if(SZ(diff) == 0){
    cout << "-1\n";
    return 0;
  }

  for(int d : diff){
    for(int del : {1, 0, -1}){
      if(check(del, d)){
//        if(del == 0 && d == 0){
//          cout << "hello\n\n";
//          cout << opt << " compares with " << cnt;
//        }
        min_self(opt, cnt);
//        if(del == 0 && d == 0){
//          cout << " to get " << opt << '\n';
//        }
      }
    }
  }

  if(opt < INF) cout << opt << '\n';
  else cout << "-1\n";
  
  return 0;
}
