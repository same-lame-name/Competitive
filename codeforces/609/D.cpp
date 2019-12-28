
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
	long long dayC, totalG, reqG, money;
	cin >> dayC >> totalG >> reqG >> money;
	vector<pair<LL, LL>> firstT, secondT, dollarR(dayC + 1), poundR(dayC + 1);
	LL minRate = INF, dayOfMin = -1;
	for(LL day = 1; day <= dayC; ++day){
		DRI(curRate);
		if(curRate < minRate){
			minRate = curRate;
			dayOfMin = day;
		}
		dollarR[day] = MP(minRate, dayOfMin);
	}
	minRate = INF, dayOfMin = -1;
	for(LL day = 1; day <= dayC; ++day){
		DRI(curRate);
		if(curRate < minRate){
			minRate = curRate;
			dayOfMin = day;
		}
		poundR[day] = MP(minRate, dayOfMin);
	}
	REP(rep, totalG){
		DRII(revT, cost);
		if(revT == 1){
			firstT.push_back(MP(cost, rep + 1));
		}else{
			secondT.push_back(MP(cost, rep + 1));
		}
	}
	sort(ALL(firstT)); sort(ALL(secondT));
	LL low = 1, high = dayC, curBest = -1;
	vector<pair<int, int>> finalChoice;
	while(low <= high){
		LL mid = low + (high - low) / 2; 
		vector<pair<int, int>> gadgetI;
		LL N = SZ(firstT), M = SZ(secondT);
		LL fRate = dollarR[mid].F, pRate = poundR[mid].F;
		LL toBuyD = dollarR[mid].S, toBuyP = poundR[mid].S;
		LL bought = 0;
		LL fIdx = 0, sIdx = 0, curRev = money;
		while(fIdx < N || sIdx < M){
			LL f = INF, s = INF;
			bool atLeast = false;
			if(fIdx < N) f = fRate * firstT[fIdx].F;
			if(sIdx < M) s = pRate * secondT[sIdx].F;
			if(f < s){
				if(f > curRev) break;
				atLeast = true;
				curRev -= f;
				gadgetI.push_back(MP(firstT[fIdx].S, toBuyD));
				fIdx++;
			}
			else if(s != INF){
				if(s > curRev) break;
				atLeast = true;
				curRev -= s;
				gadgetI.push_back(MP(secondT[sIdx].S, toBuyP));
				sIdx++;
			}
			if(!atLeast) break;
			bought++;
			if(bought == reqG) break;
		}
		bool isPossible = (bought == reqG);
		if(isPossible){
			finalChoice = gadgetI;
			curBest = mid;
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	if(curBest == -1){
		cout << -1 << endl;
		return 0;
	}
	cout << curBest << endl;
	for(auto ele : finalChoice){
		cout << ele.F << " " << ele.S << endl;
	}
	return 0;
}