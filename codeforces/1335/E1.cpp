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

int testcases, N, num[2005], cntf[2005][30], cntb[2005][30];

void solve(){
  memset(cntf, 0, sizeof cntf);
  memset(cntb, 0, sizeof cntb);
  int opt = 0;

  for(int idx = 0; idx < N; ++idx){
    for(int c = 1; c <= 26 && idx; ++c){
      cntf[idx][c] = cntf[idx - 1][c];
    }
    cntf[idx][num[idx]] += 1;
  }

//  for(int idx = 0; idx < N; ++idx){
//    for(int c = 1; c <= 26; ++c) cout << cntf[idx][c] << " ";
//    cout << '\n';
//  }

//  cout << "\n\n";

  for(int idx = N - 1; idx >= 0; --idx){
    for(int c = 1; c <= 26; ++c){
      cntb[idx][c] = cntb[idx + 1][c];
    }
    cntb[idx][num[idx]] += 1;
  }

//  for(int idx = N - 1; idx >= 0; --idx){
//    for(int c = 1; c <= 26; ++c) cout << cntb[idx][c] << " ";
//    cout << '\n';
//  }
//
//  auto l = [&](int f){
//    int most = 0;
//    for(int c = 1; c <= 26; ++c){
//      max_self(most, cntf[f][c]);
//    }
//
//    return most;
//  };
//
//  auto r = [&](int b){
//    int most = 0;
//    for(int c = 1; c <= 26; ++c){
//      max_self(most, cntb[b][c]);
//    }
//
//    return most;
//  };

  auto match = [&](int f, int b){
    int most = 0;
    for(int c = 1; c <= 26; ++c){
      max_self(most, min(cntf[f][c], cntb[b][c]));
    }

    return most;
  };
    
  auto m = [&](int f, int b){
    if(b < f) return 0;
    int most = 0;
    for(int c = 1; c <= 26; ++c){
      int cur = cntf[b][c];
      if(f) cur -= cntf[f - 1][c];
      max_self(most, cur);
    }

    return most;
  };

  opt = m(0, N - 1);

  for(int f = 0; f < N; ++f){
    for(int b = N - 1; b > f; --b){
      int mat = match(f, b);
      int mid = m(f + 1, b - 1);
      max_self(opt, 2 * mat + mid);
    }
  }

  cout << opt << '\n';

  return;
}
  
int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N;
    for(int rep = 0; rep < N; ++rep) cin >> num[rep];
    solve();
  }

  return 0;
}
