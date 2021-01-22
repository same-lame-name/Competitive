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


int main(){
	FAST_IO

	int N, loser = -1;
	queue<pair<int, int>> current, nxt;

	cin >> N;
	for(int rep = 1, x; rep <= (1 << N); ++rep){
		cin >> x;
		current.push(make_pair(x, rep));
	}

	for(int rep = 0; rep < N; ++rep){
		assert(nxt.empty());
		while(!current.empty()){
			assert(current.size() > 1);
			pair<int, int> fst = current.front();
			current.pop(); 
			pair<int, int> sec = current.front();
			current.pop();
			if(fst.first < sec.first){
				loser = fst.second;
				nxt.push(sec);
			}else{
				loser = sec.second;
				nxt.push(fst);
			}
		}

		swap(current, nxt);
	}

	cout << loser << '\n';
	return 0;
}
