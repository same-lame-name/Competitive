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

int N, k, avail[30], skip = 0, start = -1;
string in;

int main(){
  FAST_IO
  cin >> N >> k >> in;
  memset(avail, 0, sizeof avail);
  for(char c : in) avail[c - 'a']++;
//  for(int cur = 0; cur < 26; ++cur) cout << avail[cur];
//  cout << "\n\n";

  for(int cur = 0; cur <= 26; ++cur){
    if(k == 0 || k < avail[cur]){
//      cout << "hello\n\n";
//      cout << in[cur] << "\n\n";
      start = cur;
      skip = k;
      k -= avail[cur];
      break;
    }
    
    k -= avail[cur];
//    if(avail[cur]){
//      cout << char('a' + cur) << '\n';
//      cout << k << '\n';
//    }
  }

  assert(k <= 0 && start >= 0);
//  cout << char(start + 'a') << '\n';

  for(char c : in){
    if(c < 'a' + start) continue;
    if(c == 'a' + start){
      if(skip == 0) cout << c;
      else skip--;
    }else cout << c;
  }

 
  return 0;
}
