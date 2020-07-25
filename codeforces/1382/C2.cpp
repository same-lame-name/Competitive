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

int N, head, tail, testcases, cnt, a, b;
vector<int> act;
bool rev;
string A, B;

void solve(){
  head = 0, tail = N - 1;
  rev = false;
  act.clear();

  for(int idx = N - 1; idx >= 0; --idx){
    a = A[tail] - '0', b = B[idx] - '0';
    if(rev) a = !a;

    if(a != b){
      a = A[head] - '0';
      if(rev) a = !a;
      if(a == b) act.PB(1);
    
      act.PB(idx + 1);
      swap(head, tail);
      rev = !rev;
    }

    if(rev) tail++;
    else tail--;
  }

  cout << SZ(act) << " ";
  for(int ele : act) cout << ele << " ";
  cout << '\n';
  return;
}


int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> A >> B;
    solve();
  }
  return 0;
}

