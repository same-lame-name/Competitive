
#include <bits/stdc++.h>
#define PRECISION(x) cout << fixed << setprecision(x); 
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(i,n) for (int i = 0; i < n; ++i)
#define DO(X) while(X--)
#define DRI(X) int (X); cin >> X
#define DRII(X, Y) int X, Y; cin >> X >> Y
#define DRIII(X, Y, Z) int X, Y, Z; cin >> X >> Y >> Z
#define read(X) for(int &ele : (X)) cin >> ele
#define readI(X) for(int idx = 1; idx < SZ((X)); ++idx) cin >> (X)[idx]
#define debug(x) cerr << '>' << #x << ':' << x << endl
#define MP make_pair
#define PB push_back
#define F first
#define S second

using namespace std;
typedef long long LL;
const int INF = 1<<29;
inline int in() { int x; cin >> x; return x; }
template<class T> void max_self(T & a, const T & b) { if(a < b) a = b; }
template<class T> void min_self(T & a, const T & b) { if(a > b) a = b; }

int main(){
	FAST_IO 
	unordered_map<int, bool> isP = {{1, false}, {2, false}, {3, false}};
	REP(rep, 2){
		isP[in()] = true;
	}
	for(auto ele : isP){
		if(ele.second == false) cout << ele.first << endl;
	}
	return 0;
}