#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){
	FAST_IO
	int testcases, rep = 0;
	string util;
	set<char> ok;
	char last;

	cin >> testcases;
	while(testcases--){
		last = '#';
		ok.clear();
		rep = 1;
		cin >> util;
		util.push_back('$');
		for(char c : util){
			if(c != last){
				if(rep & 1) ok.insert(last);
				rep = 1;
			}else rep = rep + 1;

			last = c;
		}

		for(char c = 'a'; c <= 'z'; ++c){
			if(ok.count(c)) cout << c;
		}

		cout << '\n';
	}
	return 0;
}

