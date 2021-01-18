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
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	int testcases, w, h, n, count;
	cin >> testcases;

	while(testcases--){
		cin >> w >> h >> n;
		count = 0;
		while(w % 2 == 0){
			w /= 2;
			count++;
		}

		while(h % 2 == 0){
			h /= 2;
			count++;
		}

		assert(w & 1);
		assert(h & 1);
		assert(count < 32);

		if(n <= (1 << count)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
