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

int testcases, N, opt, pref[1005];
string in;

inline void solve(){
  N = SZ(in);
  opt = INF;
  memset(pref, 0, sizeof pref);
  for(int idx = 0; idx < N; ++idx){
    if(idx) pref[idx] += pref[idx - 1];
    pref[idx] += in[idx] - '0';
//    cout << pref[idx] << " ";
  }
//  cout << '\n';

  
//  min_self(opt, pref[N - 1]);
//  min_self(opt, N - pref[N - 1]);

  for(int idx = 0, b, a, o, t; idx < N; ++idx){
    b = pref[idx], a = pref[N - 1] - pref[idx];
//    cout << b << " " << a << '\n';

    o = (idx + 1 - b) + a;
//    cout << "  for 111110000  " << o << " ";
    t = b + (N - idx - 1 - a);
//    cout << "  for 00001111   " << t << "\n";
    if(o > t) o = t;
//    cout << o << '\n';
    min_self(opt, o);
  }

  cout << opt << '\n';
}
    



int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> in;
    solve();
  }
  return 0;
}
