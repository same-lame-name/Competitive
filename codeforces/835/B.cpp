#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){
	FAST_IO
	int k, current = 0, total = 0, count[15] = {0};
	string N;
	cin >> k >> N;
	for(char c : N){
		current += c - '0';
		count[c - '0']++;
	}

	for(int digit = 0, avail, req, take; current < k && digit < 10; ++digit){
		avail = count[digit];
		req = (k - current + 8 - digit) / (9 - digit);
		take = min(avail, req);
		total += take;
		current += take * (9 - digit);
	}

	cout << total << '\n';
	return 0;
}

