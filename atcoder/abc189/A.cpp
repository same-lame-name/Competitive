#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){
	FAST_IO
	string util;
	cin >> util;
	if(util[0] == util[1] && util[1] == util[2]) cout << "Won\n";
	else cout << "Lost\n";
	return 0;
}

