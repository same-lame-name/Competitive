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

int N;
string a, b, c;
map<char, int> cnt;
vector<pair<int, string>> winner;

int get(string &x){
  int most = 0, M = SZ(x);
  cnt.clear();

  for(char t : x) cnt[t]++;

  for(auto &[k, v] : cnt){
    int space = M - v, cur = min(v + N, M);

    if(space == 0 && N == 1){
      assert(cur == M);
      cur--;
    }

    max_self(most, cur);
  }

  return most;
}

int main(){
  FAST_IO
  cin >> N >> a >> b >> c;
  int kuro = get(a);
  int shiro = get(b);
  int katie = get(c);

  winner.PB({kuro, "Kuro"});
  winner.PB({shiro, "Shiro"});
  winner.PB({katie, "Katie"});

  sort(ALLR(winner));

  if(winner[0].F == winner[1].F){
    cout << "Draw\n";
    return 0;
  }
  
  cout << winner[0].S;

  return 0;
}

