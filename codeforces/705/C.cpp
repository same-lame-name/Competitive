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


int type, q, unread, done, noti[(int)3e5 + 7], not_acc[(int)3e5 + 7];
queue<int> nxt;
   
int main(){
  FAST_IO
  unread = done = 0;
  cin >> type >> q;

  for(int rep = 0, x, y; rep < q; ++rep){
    cin >> x >> y;
    if(x == 1){
      unread++;
      nxt.push(y);
      noti[y]++;
    }else if(x == 2){
      not_acc[y] += noti[y];
      unread -= noti[y];
      noti[y] = 0;
    }else{
      for(int itr = done, a; itr < y; ++itr){
        a = nxt.front();
        nxt.pop();
        if(not_acc[a] > 0) not_acc[a]--;
        else{
          noti[a]--;
          unread--;
        }
      }

      max_self(done, y);
    }

    cout << unread << '\n';
  }
  
  return 0;
}
