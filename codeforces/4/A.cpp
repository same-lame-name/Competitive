#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N;
	if(N % 2) cout << "NO" << endl;
	else{
		N /= 2;
		if(N <= 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}