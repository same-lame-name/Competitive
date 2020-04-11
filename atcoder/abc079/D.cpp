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
	
	int H, W, minCost = 0; cin >> H >> W;
	
	int cost[10][10];
	for(int row = 0; row < 10; ++row){
		for(int col = 0; col < 10; ++col){
			cin >> cost[row][col];
		}
	}
	
	for(int via = 0; via < 10; ++via){
		for(int from = 0; from < 10; ++from){
			for(int to = 0; to < 10; ++to){
				min_self(cost[from][to], cost[from][via] + cost[via][to]);
			}
		}
	}
	
	for(int row = 0; row < H; ++row){
		for(int col = 0; col < W; ++col){
			int x; cin >> x;
			if(x == -1) continue;
			minCost += cost[x][1];
		}
	}
	
	cout << minCost << "\n";
	
	return 0;
}
