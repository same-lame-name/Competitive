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

int N, C, opt = INF, per[5], cst[35][35];
bool used[35];
int grp[5][35];

int main(){
  FAST_IO

  cin >> N >> C;

  for(int r = 1; r <= C; ++r){
    for(int c = 1; c <= C; ++c){
      cin >> cst[r][c];
    }
  }

  for(int r = 1; r <= N; ++r){
    for(int c = 1, x; c <= N; ++c){
      cin >> x;
      grp[(r + c) % 3][x]++;
    }
  }

  for(int o = 1; o <= C; ++o){
    for(int t = o + 1; t <= C; ++t){
      for(int th = t + 1, cost; th <= C; ++th){
        per[0] = o, per[1] = t, per[2] = th;
        do{
          cost = 0;
          for(int g = 0; g < 3; ++g){
            for(int c = 1; c <= C; ++c){
              cost += grp[g][c] * cst[c][per[g]];
            }
          }

          min_self(opt, cost);
        }while(next_permutation(per, per + 3));
      }
    }
  }

  cout << opt << '\n';
  return 0;
}