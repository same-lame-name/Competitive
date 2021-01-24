#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){
	FAST_IO
	int N, limit, current = 0;
	cin >> N >> limit;
	limit *= 100;
	for(int rep = 1, val, conc; rep <= N; ++rep){
		cin >> val >> conc;
		current += val * conc;
		if(current > limit){
			cout << rep << '\n';
			return 0;
		} 
	}

	cout << "-1\n";
	return 0;
}

