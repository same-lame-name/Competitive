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

map<char, char> comp;
string A, B;
char a, b;
bool ok = true;
int cnt = 0;

int main(){
  FAST_IO
  cin >> A >> B;

  for(int idx = 0; idx < SZ(A); ++idx){
    a = A[idx], b = B[idx];
    if(comp.count(a) && comp[a] != b) ok = false;
    if(comp.count(b) && comp[b] != a) ok = false;

    if(!ok){
      cout << "-1\n";
      return 0;
    }
    
    if(comp.count(a) == 0 && a != b) cnt++;
    comp[a] = b;
    comp[b] = a;
  }

  cout << cnt << '\n';
  for(char x = 'a'; x <= 'z'; ++x){
    if(comp.count(x) && comp[x] > x) cout << x << " " << comp[x] << '\n';
  }
  return 0;
}

