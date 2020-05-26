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

LL num[3][(int)1e5 + 5], lt[(int)1e5 + 5], N;
LL cnt = 0;

int main(){
  FAST_IO
  cin >> N;
  for(int rep = 0; rep < 3; ++rep){
    for(int itr = 1; itr <= N; ++itr){
      cin >> num[rep][itr];
    }

    sort(num[rep] + 1, num[rep] + N + 1);
  }

  int lft = 0;
  for(int rgt = 1; rgt <= N; ++rgt){
    while(lft <= N && num[0][lft] < num[1][rgt]) lft++;
    lt[rgt] = lft - 1;
  }

  for(int rep = 1; rep <= N; ++rep){
    lt[rep] += lt[rep - 1];
  }

  lft = 0;
  for(int rgt = 1; rgt <= N; ++rgt){
    while(lft <= N && num[1][lft] < num[2][rgt]) lft++;
    cnt += (LL)lt[lft - 1];
  }
    
  cout << cnt << '\n';
  return 0;
}