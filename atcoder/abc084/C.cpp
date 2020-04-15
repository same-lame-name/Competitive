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

class info{
public:
  int cost, start, freq;
  info(int c, int s, int f) : cost(c), start(s), freq(f){}
};

int main(){
  FAST_IO  
  
  int N; cin >> N;
  vector<info> station;

  for(int rep = 0; rep < N - 1; ++rep){
    int cost, start, freq;
    cin >> cost >> start >> freq;
    station.EB(cost, start, freq);
  }
  
  function<int(int, int)> util;
  util = [&](int idx, int t){
    if(idx == N - 1) return 0;
    int c = station[idx].cost, s = station[idx].start, f = station[idx].freq;
    int cur = c;
    if(s > t){
      cur += s - t;
      t = s;
    }
    if(t % f){
      cur += f - t % f;
      t += f - t % f;
    }

    return cur + util(idx + 1, t + c);
  };

  for(int st = 0; st < N - 1; ++st){
    cout << station[st].start + util(st, station[st].start) << "\n";
  }
  cout << "0\n";


  return 0;
}