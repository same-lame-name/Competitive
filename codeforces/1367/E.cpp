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

int testcases, N, k, cnt[30];
string in;

void solve(){
  for(int c = 0; c < 26; ++c) cnt[c] = 0;
  for(char c : in) cnt[c - 'a']++;

  for(int len = N, atmost, link, period; len > 0; --len){
    period = __gcd(len, k);
    link = len / __gcd(len, k);
    atmost = 0;
    for(int c = 0; c < 26; ++c) atmost += cnt[c] / link;

    if(atmost >= period){
      cout << len << '\n';
      return;
    }
  }

  assert(false);
  cout << 0 << '\n';
  
  return;
}
    
int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> k >> in;
    solve();
  }
  return 0;
}
