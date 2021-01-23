#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool isHello(string &s){
	string hello = "hello";
	int curIdx = 0;
	for(char c : s){
		if(c == hello[curIdx]) curIdx++;
		if(curIdx == (int)hello.size()) break;
	}

	return curIdx == (int)hello.size();
}

int main(){
	FAST_IO

	string s;
	cin >> s;

	if(isHello(s)) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
