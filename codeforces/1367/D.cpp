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

int testcases, N, placed, cur, diff[55], cnt[30], config[55];
string in;
char to[55];
bool done[55];
vector<int> indices;

void solve(){
  memset(done, false, sizeof done);
  for(int idx = 0; idx < N; ++idx) config[idx] = 0;

  for(int c = 0; c < 26; ++c) cnt[c] = 0;
  for(char c : in) cnt[c - 'a']++;
  placed = 0, cur = 25;

  while(placed < N){
    assert(cur >= 0);
    indices.clear();
    for(int idx = 0; idx < N; ++idx){
      if(config[idx] == diff[idx] && !done[idx]){
        indices.PB(idx);
      }
    }

    while(cur >= 0 && cnt[cur] < SZ(indices)) cur--;
    assert(cur >= 0);

    
    for(int ele : indices){
      done[ele] = true;
      to[ele] = char('a' + cur);
    }


    for(int ele : indices){
      for(int idx = 0; idx < N; ++idx){
        if(done[idx]) continue;
        config[idx] += abs(ele - idx);
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
