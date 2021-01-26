#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){
	FAST_IO
	int testcases, N, remainder, quotient;
	cin >> testcases;
	while(testcases--){
		cin >> N;
		quotient = N / 2020, remainder = N - quotient * 2020;
		if(quotient >= remainder) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

