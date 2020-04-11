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
	
	int N, c, maxClash = 0; cin >> N >> c;
	int time[(int)2e5 + 5], chTime[(int)2e5 + 5];
	unordered_map<int, vector<pair<int, int>>> channel;
	memset(time, 0, sizeof time);
	
	for(int rep = 0; rep < N; ++rep){
		int from, to, ch; cin >> from >> to >> ch;
		channel[ch].EB(from, to);
	}
	
	for(auto &ele : channel){
		memset(chTime, 0, sizeof chTime);
		for(auto &t : ele.S){
			int from = t.F, till = t.S;
			chTime[2 * from - 1]++;
			chTime[2 * till]--;
		}
		
		for(int t = 1; t <= 2e5; ++t){
			chTime[t] += chTime[t - 1];
			if(chTime[t]) time[t]++;
		}
	}
		
	for(auto ele : time) max_self(maxClash, ele);
		
	

		
	cout << maxClash << "\n";
	
	return 0;
}
