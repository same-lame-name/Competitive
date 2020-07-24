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

int N, age[(int)1e5 + 5], diss[(int)1e5 + 5];
vector<int> indices;

int get(int idx){
  // ok points to the first index that is smaller than current value.
  int left = 0, right = SZ(indices) - 1, ok = SZ(indices);
  while(left <= right){
    int mid = left + (right - left) / 2;
    if(age[indices[mid]] < age[idx]){
      ok = mid;
      right = mid - 1;
    }else left = mid + 1;
  }

  assert(ok < SZ(indices));
  return indices[ok] - idx - 1;
}


int main(){
  FAST_IO
  cin >> N;
  for(int idx = 0; idx < N; ++idx) cin >> age[idx];
  memset(diss, -1, sizeof diss);

  for(int idx = N - 1; idx >= 0; --idx){
    if(indices.empty() || age[indices.back()] >= age[idx]){
      indices.PB(idx);
      continue;
    }

    diss[idx] = get(idx);
  }
    
  for(int idx = 0; idx < N; ++idx) cout << diss[idx] << " ";
  return 0;
}

