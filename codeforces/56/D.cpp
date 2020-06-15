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

int N, M, memo[1005][1005];
string in, text;
char action[1005][1005];
map<char, pair<int, int>> diff;

int solve(int f, int t){
  if(f == N || t == M){
    return (N - f) + (M - t);
  }

  int &cst = memo[f][t], x;
  if(cst != -1) return cst;
  cst = INF;

  if(in[f] == text[t]){
    action[f][t] = 'x';
    return cst = solve(f + 1, t + 1);
  }

  // Try replacing character at postion t.
  x = 1 + solve(f + 1, t + 1);
  if(x < cst){
    action[f][t] = 'r';
    cst = x;
  }
  
  // Try inserting at the position t.
  x = 1 + solve(f, t + 1);
  if(x < cst){
    action[f][t] = 'i';
    cst = x;
  }

  // Try deleting the character at position t.
  x = 1 + solve(f + 1, t);
  if(x < cst){
    action[f][t] = 'd';
    cst = x;
  }

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

  diff['x'] = MP(1, 1);
  diff['i'] = MP(0, 1);
  diff['d'] = MP(1, 0);
  diff['r'] = MP(1, 1);

  cout << solve(0, 0) << '\n';
  int f = 0, t = 0;
  while(f < N && t < M){
    char op = action[f][t];
    print(op, t);
    f += diff[op].F;
    t += diff[op].S;
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
