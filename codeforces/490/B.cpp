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

int N, head, nxt[(int)1e6 + 7];
unordered_set<int> h, t;

int main(){
  FAST_IO
  cin >> N;
  for(int rep = 0, a, b; rep < N; ++rep){
    cin >> a >> b;
    h.insert(a);
    t.insert(b);
    nxt[a] = b;
  }
  
  for(int ele : h){
    if(t.count(ele)) continue;
    head = ele;
    break;
  }

  int even = head, odd = nxt[0];
  for(int rep = 0; rep < N; ++rep){
    if(rep & 1){
      cout << odd << " ";
      odd = nxt[odd];
    }else{
      cout << even << " ";
      even = nxt[even];
    }
  }

  assert(even == 0 || odd == 0);

  return 0;
}
