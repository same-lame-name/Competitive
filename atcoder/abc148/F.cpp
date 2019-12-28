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
	DRIII(N, tPos, aPos);
	vector<vector<int>> adjList(N + 1);
	REP(rep, N){
		DRII(oneV, secV);
		adjList[oneV].push_back(secV);
		adjList[secV].push_back(oneV);
	}
	vector<int> distance(N + 1, INF);
	queue<int> BFS;
	BFS.push(aPos);
	distance[aPos] = 0;
	while(!BFS.empty()){
		int curPos = BFS.front(); BFS.pop();
		for(int adj : adjList[curPos]){
			if(distance[adj] > distance[curPos] + 1){
				distance[adj] = distance[curPos] + 1;
				BFS.push(adj);
			}
		}
	}
	vector<int> _distance(N + 1, INF);
	int maxAllowed = 0;
	if(distance[tPos] > 0){
		BFS.push(tPos);
		_distance[tPos] = 0;
	}
	while(!BFS.empty()){
		int curPos = BFS.front(); BFS.pop();
		max_self(maxAllowed, distance[curPos]);
		for(int adj : adjList[curPos]){
			if(_distance[adj] > _distance[curPos] + 1 && distance[adj] > _distance[curPos] + 1){
				_distance[adj] = _distance[curPos] + 1;
				BFS.push(adj);
			}
		}
	}
	cout << max(maxAllowed - 1, 0) << endl;
	return 0;
}