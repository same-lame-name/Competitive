
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
	DRII(N, K);
	vector<int> gain(3);
	vector<vector<int>> group(K);
	REP(rep, 3) cin >> gain[rep];
	string moves; cin >>  moves;
	for(int idx = 0; idx < N; ++idx) group[idx % K].push_back(idx);
	int maxProfit = 0;
	auto winning = [&](char a, char b){
		if(a == 'r' && b== 's'){
			return gain[0];
		}
		if(a == 's' && b == 'p'){
			return gain[1];
		}
		if(a == 'p' && b == 'r'){
			return gain[2];
		}
		return 0;
	};
	for(int modF = 0; modF < K; ++modF){
		int M = SZ(group[modF]);
		vector<vector<int>> curProfit(M, vector<int>(3));
		for(int idx = 0; idx < M; ++idx){
			curProfit[idx][0] = (idx > 0 ? max(curProfit[idx - 1][1], curProfit[idx - 1][2]) : 0)
								+ winning('r', moves[group[modF][idx]]); 
			curProfit[idx][1] = (idx > 0 ? max(curProfit[idx - 1][0], curProfit[idx - 1][2]) : 0)
								+ winning('s', moves[group[modF][idx]]); 
			curProfit[idx][2] = (idx > 0 ? max(curProfit[idx - 1][1], curProfit[idx - 1][0]) : 0)
								+ winning('p', moves[group[modF][idx]]); 
		}
		maxProfit += max({curProfit[M - 1][0], curProfit[M - 1][1], curProfit[M - 1][2]});
	}
	cout << maxProfit << endl;
	return 0;
}