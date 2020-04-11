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
	
	int N, best = -INF; cin >> N;
	vector<int> shops(N);
	vector<vector<int>> profit(N, vector<int>(15));
	
	auto getBinary = [&](int a){
		for(int pos = 9; pos >= 0; --pos) cout << ((a & (1 << pos)) ? 1 : 0) << " ";
		cout << endl;
	};
	
	auto getInt = [&](int a, int b){
		int count = 0;
		for(int pos = 0; pos < 10; ++pos){
			if((a & (1 << pos)) && (b & (1 << pos))) count++;
		}
		
		return count;
	};
	
	for(int rep = 0; rep < N; ++rep){
		int &ele = shops[rep];
		for(int pos = 0; pos < 10; ++pos){
			int open; cin >> open;
			ele |= (open << pos);
		}
	}
	
	for(int s = 0; s < N; ++s){
		for(int clash = 0; clash <= 10; ++clash){
			cin >> profit[s][clash];
		}
	}
	

	
	for(int mask = 1; mask < (1 << 10); ++mask){
		int cur = 0;
		
		for(int s = 0; s < N; ++s){
			int inter = getInt(shops[s], mask);
			cur += profit[s][inter];
		}

		max_self(best, cur);
	}
			
	cout << best << "\n";
			
	return 0;
}
