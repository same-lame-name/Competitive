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

int N, M, memo[1005][1005];
string in, text;
char action[1005][1005];

int solve(int f, int t){
  if(f == N || t == M){
    return (N - f) + (M - t);
  }

  int &cst = memo[f][t];
  if(cst != -1) return cst;
  cst = INF;

  if(in[f] == text[t]){
    action[f][t] = 'x';
    return cst = solve(f + 1, t + 1);
  }

  // Try replacing character at postion t.
  if(min_self(cst, 1 + solve(f + 1, t + 1))) action[f][t] = 'r';
  
  // Try inserting at the position t.
  if(min_self(cst, 1 + solve(f, t + 1))) action[f][t] = 'i';

  // Try deleting the character at position t.
  if(min_self(cst, 1 + solve(f + 1, t))) action[f][t] = 'd';

  return cst;
}

void print(char op, int t){
  if(op == 'x') return;

  if(op == 'i'){
    cout << "INSERT " << t + 1 << ' ' << text[t] << '\n';
  }else if(op == 'd'){
    cout << "DELETE " << t + 1 << '\n';
  }else if(op == 'r'){
    cout << "REPLACE " << t + 1 << ' ' << text[t] << '\n';
  }

  return;
}


int main(){
  FAST_IO
  cin >> in >> text;
  N = SZ(in), M = SZ(text);
  memset(memo, -1, sizeof memo);

  cout << solve(0, 0) << '\n';
  int f = 0, t = 0;
  while(f < N && t < M){
    char op = action[f][t];
    print(op, t);
    if(op != 'i') f++;
    if(op != 'd') t++;
  }

  while(f < N){
    cout << "DELETE " << M + 1 << '\n';
    f++;
  }

  while(t < M){
   cout << "INSERT " << t + 1 << ' ' << text[t] << '\n'; 
   t++;
  }

  return 0;
}
