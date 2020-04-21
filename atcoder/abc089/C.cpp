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
  
  int N; cin >> N;
  int count[5] = {0};

  for(int rep = 0; rep < N; ++rep){
    string s; cin >> s;
    if(s[0] == 'M') count[0]++;
    else if(s[0] == 'A') count[1]++;
    else if(s[0] == 'R') count[2]++;
    else if(s[0] == 'C') count[3]++;
    else if(s[0] == 'H') count[4]++;
  }

  LL ways = 0;

  for(int start = 0; start < 5; ++start){
    for(int mid = start + 1; mid < 5; ++mid){
      for(int end = mid + 1; end < 5; ++end){
        ways += (LL)count[start] * count[mid] * count[end];
      }
    }
  }

  cout << ways << "\n";

  return 0;
}