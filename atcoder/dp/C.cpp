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

int N, opt[(int)1e5 + 5][3], val[(int)1e5 + 5][3];

int main(){
  FAST_IO  
  cin >> N;
  for(int rep = 0; rep < N; ++rep){
    for(int itr = 0; itr < 3; ++itr){
      cin >> val[rep][itr];
      opt[rep][itr] = 0;
    }
  }

  opt[0][0] = val[0][0], opt[0][1] = val[0][1], opt[0][2] = val[0][2];

  for(int day = 0; day < N - 1; ++day){
    for(int c = 0; c < 3; ++c){
      for(int p = 0; p < 3; ++p){
        if(p == c) continue;
        max_self(opt[day + 1][p],
                 opt[day][c] + val[day + 1][p]);
      }
    }
  }

  cout << max({opt[N - 1][0], opt[N - 1][1], opt[N - 1][2]});
  return 0;
}