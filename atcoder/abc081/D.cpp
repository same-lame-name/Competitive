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
  bool reverse = false;
  int N, maxIdx = 1, minIdx = 1; cin >> N;
  vector<int> nums(N + 1) ;
  nums[0] = -INF;
  for(int idx = 1; idx <= N; ++idx) cin >> nums[idx];

  for(int idx = 1; idx <= N; ++idx){
    if(nums[idx] > nums[maxIdx]) maxIdx = idx;
    if(nums[idx] < nums[minIdx]) minIdx = idx;
  }

  cout << 2 * N - 1 << "\n";

  auto util = [&](int crit){
    for(int idx = 1; idx <= N; ++idx){
      cout << crit << " " << idx << "\n";
    }
    return;
  };

  if(abs(nums[maxIdx]) < abs(nums[minIdx])){
    util(minIdx);
    reverse = true;
  }
  else util(maxIdx);


  if(reverse){
    for(int idx = N - 1; idx >= 1; --idx){
      cout << idx + 1 << " " << idx << "\n";
    }
  }else{
    for(int idx = 2; idx <= N; ++idx){
      cout << idx - 1 << " " << idx << "\n";
    }
  }
  return 0;
}