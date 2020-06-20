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

int N, M, c, total = 0;

int main(){
  FAST_IO
  cin >> N >> M >> c;
  vector<int> b(M);
  for(int &ele : b) cin >> ele;

  for(int r = 0; r < N; ++r){
    int okay = 0;
    for(int rep = 0, x; rep < M; ++rep){
      cin >> x;
      okay += x * b[rep];
    }

    okay += c;
    if(okay > 0) total++;
  }

  cout << total << '\n';
  return 0;
}
