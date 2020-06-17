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

int testcases, N, placed, cur, diff[55], cnt[30];
string in, to;
vector<int> indices;

void solve(){
  memset(cnt, 0, sizeof cnt);
  to.resize(N, ' ');

  for(char c : in) cnt[c - 'a']++;
  placed = 0, cur = 25;

  while(placed < N){
    indices.clear();
    for(int idx = 0; idx < N; ++idx){
      if(diff[idx] == 0) indices.PB(idx);
    }

    while(cur >= 0 && cnt[cur] < SZ(indices)) cur--;
    
    for(int ele : indices){
      diff[ele] = INF;
      to[ele] = char('a' + cur);
    }

    for(int ele : indices){
      for(int idx = 0; idx < N; ++idx){
        if(diff[idx] == INF) continue;
        diff[idx] -= abs(idx - ele);
      }
    }

    cur--;
    placed += SZ(indices);
  }

  for(int idx = 0; idx < N; ++idx) cout << to[idx];
  cout << '\n';
}
     


  
   
int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> in >> N;
    for(int rep = 0; rep < N; ++rep) cin >> diff[rep];
    solve();
  }
  return 0;
}
