
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
	string word; cin >> word;
	int lowerC = 0, upperC = 0;
	for(char c : word){
		if(c >= 'a' && c <= 'z') lowerC++;
		else upperC++;
	}
	if(lowerC >= upperC){
		for(char &c : word){
			if(c < 'a') c += 32;
		}
		cout << word << "\n";
	}else{
		for(char &c : word){
			if(c > 'Z') c -= 32;
		}
		cout << word << "\n";
	}
	return 0;
}