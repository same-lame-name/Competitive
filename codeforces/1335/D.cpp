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

int testcases;
string sudoku[10];

void solve(){
  int start = 0;
  for(int r = 0; r < 9; r += 3){
    for(int rep = 0, c = start; rep < 3; ++rep, c += 3){
//        cout << r + rep << " & " << c << " then ---> ";
      if(sudoku[r + rep][c] == '9') sudoku[r + rep][c] = '1';
      else sudoku[r + rep][c] += 1;
    }
    start++;
//    cout << "\n";
  }

  return;
}
  
int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    for(int rep = 0; rep < 9; ++rep) cin >> sudoku[rep];
    solve();

    for(int rep = 0; rep < 9; ++rep) cout << sudoku[rep] << '\n';
    cout << '\n';
  }

  return 0;
}
