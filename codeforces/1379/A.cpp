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

int testcases, N;
string in, text = "abacaba", util;

void print(){
  cout << "Yes\n";
  for(char c : util){
    if(c == '?') cout << 'z';
    else cout << c;
  }
  cout << '\n';
  return;
}

int occ(){
  int cnt = 0;
  for(int idx = 0, ok; idx + 6 < N; ++idx){
    ok = true;
    for(int j = 0; j < 7; ++j){
      if(util[idx + j] != text[j]) ok = false;
    }

    cnt += ok;
  }

  return cnt;
}

void solve(){
  int cnt = occ();

  if(cnt == 1) print();
  else if(cnt > 1) cout << "No\n";
  else{
    assert(cnt == 0);

    for(int idx = 0, ok; idx + 6 < N; ++idx){
      ok = true;
      for(int j = 0; j < 7; ++j){
        if(in[idx + j] != '?' && in[idx + j] != text[j]) ok = false;
      }

      if(!ok) continue;
      assert(util == in);

      for(int j = 0; j < 7; ++j) util[idx + j] = text[j];
      if(occ() == 1){
        print();
        return;
      }

      util = in;
    }

    assert(util == in);
    cout << "No\n";
  }

  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> in;
    util = in;
    solve();
  }
  return 0;
}

