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

string in, bst;
int N;
bool zero = false;

void compare(string a){
  if(SZ(a) > SZ(bst)) bst = a;
  return;
}

void util(int st){
  string cur = in.substr(st);

  int ext = 0, M = SZ(cur);
  for(char c : cur) ext += c - '0';
  ext = ext % 3;

  // Already divisible by three.
  if(ext == 0){
    compare(cur);
    return;
  }

  // Check if we can make it divisible by removing only one.
  for(int idx = M - 1, dig; idx > 0; --idx){
    dig = cur[idx] - '0';
    if(dig % 3 == ext){
      cur.erase(idx, 1);
      compare(cur);
      return;
    }
  }

  assert(SZ(cur) == M);
  // Check if we can make it divisible by removing two.
  for(int idx = M - 1, dig, cnt = 0; idx > 0; --idx){
    dig = cur[idx] - '0';
    if(dig % 3 == 0) continue;
    if(dig % 3 != ext){
      cur.erase(idx, 1);
      cnt++;
    }

    if(cnt == 2){
      compare(cur);
      return;
    }
  }

  return;
}

int main(){
  FAST_IO
  cin >> in;

  N = SZ(in);
  for(int idx = 0, cnt = 0; idx < N; ++idx){
    if(in[idx] == '0'){
      zero = true;
      continue;
    }

    cnt++;
    if(cnt <= 3) util(idx);
  }

  if(SZ(bst)) cout << bst << '\n';
  else if(zero) cout << "0\n";
  else cout << "-1\n";

  return 0;
}

