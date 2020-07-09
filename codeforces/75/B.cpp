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

string name, util, x, ac, y;
int N;
map<string, int> pri;
unordered_set<string> all;
vector<string> order;

int main(){
  FAST_IO
  cin >> name >> N;

  auto up = [&](string &a, string &b){
    if(a != name && b != name) return;

    assert(a != b);
    if(a != name) swap(a, b);
    int &val = pri[b];

    if(ac == "likes") val += 5;
    else if(ac == "posted") val += 15;
    else val += 10;

    return;
  };

  cin.ignore();
  for(int rep = 0; rep < N; ++rep){
    getline(cin, util);
    stringstream ss(util);
    
    ss >> x >> ac >> y;
    if(ac != "likes") ss >> y;

    y.pop_back();
    y.pop_back();

    up(x, y);

    if(x != name) all.insert(x);
    if(y != name) all.insert(y);

  }

  for(string ele : all) order.PB(ele);

  sort(ALL(order), [](string a, string b){
    if(pri[a] != pri[b]) return pri[a] > pri[b];
    return a < b;
  });

  for(string &ele : order) cout << ele << '\n';
  return 0;
}

