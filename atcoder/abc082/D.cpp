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
 
template<class T> void max_self(T & a, const T & b) { if(a < b) a = b; }
template<class T> void min_self(T & a, const T & b) { if(a > b) a = b; }
typedef long long LL;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);



int main(){
  FAST_IO  
  const int nax = 1e4 + 7;
  string s; cin >> s;
  int x, y, necc = 0; cin >> x >> y;
  vector<int> disp[2];
  vector<vector<bool>> hori, verti;

  for(int ins = 0, cons = 0, turn = 1, fst = true; ins <= SZ(s); ++ins){
    if(ins == SZ(s) || s[ins] == 'T'){
      if(fst){
        necc = cons;
        fst = false;
        cons = 0;
        continue;
      }
      disp[turn].PB(cons);
      turn = !turn;
      cons = 0;
    }else cons++;
  }

  int X = SZ(disp[0]), Y = SZ(disp[1]);
  hori.resize(X + 1); verti.resize(Y + 1);

  for(int pos = 0; pos <= X; ++pos) hori[pos].resize(2 * nax, false);
  for(int pos = 0; pos <= Y; ++pos) verti[pos].resize(2 * nax, false);

  hori[0][necc + nax] = true;
  verti[0][0 + nax] = true;

  for(int pos = 0; pos < X; ++pos){
    for(int t = -8000; t <= 8000; ++t){
      if(hori[pos][t + nax]){
        hori[pos + 1][t - disp[0][pos] + nax] = true;
        hori[pos + 1][t + disp[0][pos] + nax] = true;
      }
    }
  }

  for(int pos = 0; pos < Y; ++pos){
    for(int t = -8000; t <= 8000; ++t){
      if(verti[pos][t + nax]){
        verti[pos + 1][t - disp[1][pos] + nax] = true;
        verti[pos + 1][t + disp[1][pos] + nax] = true;
      }
    }
  }
  
  if(hori[X][x + nax] && verti[Y][y + nax]) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}