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

int N, opt = 0, balance = 0;
string in;
map<int, int> fst;

int main(){
  FAST_IO
  fst[0] = -1;
  cin >> N >> in;

  for(int idx = 0; idx < N; ++idx){
    if(in[idx] == '0') balance--;
    else balance++;

    if(fst.count(balance)) max_self(opt, idx - fst[balance]);
    else fst[balance] = idx;
  }

  cout << opt << '\n';
  return 0;
}

