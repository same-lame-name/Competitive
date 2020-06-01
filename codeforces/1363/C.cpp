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

int testcases, N, sp, degree, moves;

int main(){
  FAST_IO
  cin >> testcases; 
  while(testcases--){
    cin >> N >> sp;
    degree = moves = 0;
    for(int rep = 0, x, y; rep < N - 1; ++rep){
      cin >> x >> y;
      if(x == sp || y == sp) degree++;
    }

    moves = N - 3; 
    // if special node is leaf or isolated (degree <= 1)
    // OR if number of safe moves is odd, second player takes risky move.
    if(degree <= 1 || (moves & 1)) cout << "Ayush\n";
    else cout << "Ashish\n";
  }
  return 0;
}
