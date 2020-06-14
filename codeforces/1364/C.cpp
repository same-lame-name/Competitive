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

int N, num[(int)1e5 + 7];
bool present[(int)1e5 + 5];

int main(){
  FAST_IO
  cin >> N;
  for(int rep = 0; rep < N; ++rep){
    cin >> num[rep];
    present[num[rep]] = true;
  }

  for(int p = 0, l = 0; p < N; ++p){
    if(p && num[p] != num[p - 1]){
      cout << num[p - 1] << " ";
      continue;
    }

    while(present[l]) l++;
    present[l] = true;
    cout << l << " ";
  }

  return 0;
}
