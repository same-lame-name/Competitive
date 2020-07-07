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

string in;
int N, ext = 0, penalty = 0, opt = INF;
vector<int> indices[5], bst;

int main(){
  FAST_IO
  cin >> in;
  N = SZ(in);

  for(int idx = N - 1, dig; idx >= 0; --idx){
    dig = in[idx] - '0';
    dig = dig % 3;
    ext += dig;
    if(SZ(indices[dig]) < 2) indices[dig].PB(idx);
  }

  ext = ext % 3;
  if(ext == 0) goto direct;

  for(int idx = 1; idx < N; ++idx){
    if(in[idx] == '0') penalty++;
    else break;
  }

  for(int use : {1, 2}){
    int cst = (use == ext ? 1 : 2);
    if(SZ(indices[use]) < cst) continue;

    bool front = false;
    vector<int> cur;
    for(int rep = 0, idx; rep < cst; ++rep){
      idx = indices[use][rep];
      cur.PB(idx);
      if(idx == 0) front = true;
    }

    if(front) cst += penalty;
    if(min_self(opt, cst)) bst = cur;
  }
  
  if(SZ(bst) == N){
    cout << "-1\n";
    return 0;
  }

  for(int idx : bst) in.erase(idx, 1);
  
  direct:
  int idx = 0;
  while(idx < SZ(in) - 1 && in[idx] == '0') idx++;
  in = in.substr(idx);

  cout << in;
  return 0;
}

