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

  int N, cnt = 0;
  set<pair<int, int>> red;
  vector<pair<int, int>> pts;
  vector<int> greedy;

  cin >> N;

  for(int rep = 0, x, y; rep < N; ++rep){
    cin >> x >> y;
    pts.EB(x, y);
    red.insert({x, y});
  }

  for(int rep = 0, x, y; rep < N; ++rep){
    cin >> x >> y;
    pts.EB(x, y);
  }

  sort(ALL(pts));

//  cout << "----------------------------\n";
//  for(auto ele : pts) cout << ele.F << "  " << ele.S << "\n";
//  cout << "-----------------------------\n";
//  for(auto ele : red) cout << ele.F << "  " << ele.S << "\n";
//  cout << "-----------------------------\n";

  for(auto ele : pts){
    if(red.count(ele)){
//      cout << ele.F << "  " << ele.S << "\n";
      greedy.PB(ele.S);
      continue;
    }
    int del = -1;
    for(int idx = 0, maxY = -1; idx < SZ(greedy); ++idx){
      if(greedy[idx] < ele.S && greedy[idx] > maxY){
        maxY = greedy[idx];
        del = idx;
      }
    }

    if(del != -1){
      cnt++;
      greedy.erase(greedy.begin() + del);
    }
  }

//  cout << "----------------------------\n";
  cout << cnt << "\n";
  return 0;
}