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

map<int, pair<int, int>> info;
int N, k;

int main(){
  FAST_IO
  cin >> N;
  vector<int> ele;
  for(int rep = 1; rep <= N; ++rep){
    cin >> k;
    ele.resize(k);
    int total = 0, diff;
    for(int &x : ele){
      cin >> x;
      total += x;
    }

    vector<pair<int, int>> toadd;
    for(int idx = 1; idx <= SZ(ele); ++idx){
      diff = total - ele[idx - 1];
      if(info.count(diff)){
        cout << "YES\n";
        cout << info[diff].F << " " << info[diff].S << "\n";
        cout << rep << " " << idx << "\n";
        return 0;
      }
      toadd.PB(MP(diff, idx));
    }

    for(auto &x : toadd){
      info[x.F] = MP(rep, x.S);
    }
  }

  cout << "NO\n";
  return 0;
}
