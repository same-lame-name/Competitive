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

int N, M, moves = 0, pos[(int)1e5 + 5];
vector<int> diff;

int main(){
  FAST_IO
  cin >> N >> M;
  for(int rep = 0; rep < M; ++rep) cin >> pos[rep];
  sort(pos, pos + M);

  moves = pos[M - 1] - pos[0];
//  cout << moves << '\n';

  for(int x = 1; x < M; ++x) diff.PB(pos[x] - pos[x - 1]);
  sort(ALLR(diff));

//  for(int ele : diff) cout << ele << " ";

//  cout << SZ(diff) << '\n';

  for(int rep = 0; rep < min(N - 1, SZ(diff)); ++rep){
    moves -= diff[rep];
  }
    
  cout << moves << '\n';
  return 0;
}
