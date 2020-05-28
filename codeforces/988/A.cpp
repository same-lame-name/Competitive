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

map<int, int> indices;
int N, k;

int main(){
  FAST_IO
  cin >> N >> k;
  for(int idx = 1, a; idx <= N; ++idx){
    cin >> a;
    if(SZ(indices) < k) indices[a] = idx;
  }

  if(SZ(indices) < k) cout << "NO\n";
  else{
    cout << "YES\n";
    for(auto [key, v] : indices) cout << v << " ";
  }
    
  return 0;
}
