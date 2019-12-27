
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
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif
	FAST_IO 
	DRI(len);
	string input; cin >> input;
	vector<vector<int>> maxAlt(3, vector<int>(2, 0));
	for(int idx = 0; idx < len; ++idx){
		int curEle = (input[idx] == '1');
		maxAlt[2][curEle] = max({maxAlt[2][curEle], maxAlt[2][!curEle] + 1, maxAlt[1][!curEle] + 1});
		maxAlt[1][!curEle] = max({maxAlt[1][!curEle], maxAlt[1][curEle] + 1, maxAlt[0][curEle] + 1});
		maxAlt[0][curEle] = max({maxAlt[0][curEle], maxAlt[0][!curEle] + 1});
	}
	cout << max(maxAlt[2][0], maxAlt[2][1]) << endl;
	return 0;
}