#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
const int N = (int)2e5 + 7;

long long choose(int k){
	return (long long)k * (k - 1) / 2;
}

int main(){
	FAST_IO
	int testcases, a, b, k;
	long long total;
	cin >> testcases;
	while(testcases--){
		map<int, int> boyFreq, girlFreq;
		total = 0;
		cin >> a >> b >> k;

		for(int rep = 0, boy; rep < k; ++rep){
			cin >> boy;
			boyFreq[boy]++;
		}

		for(int rep = 0, girl; rep < k; ++rep){
			cin >> girl;
			girlFreq[girl]++;
		}

		total += choose(k);
		for(auto &ele : boyFreq) total -= choose(ele.second);
		for(auto &ele : girlFreq) total -= choose(ele.second);

		cout << total << '\n';
	}
	return 0;
}

