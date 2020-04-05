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
 
template<class T> void max_self(T & a, const T & b) { if(a < b) a = b; }
template<class T> void min_self(T & a, const T & b) { if(a > b) a = b; }
typedef long long LL;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);



int main(){
	FAST_IO
	
	string input; cin >> input;
	int Q, op; cin >> Q;
	bool rev = false;
	char c;
	deque<char> front, rear;
	
	auto util = [&](char add, bool key){
		if(rev ^ key) front.push_back(add);
		else rear.push_back(add);
	};
	
	auto print = [&](deque<char> &a, bool role){
		while(!role && !a.empty()){
			cout << a.front();
			a.pop_front();
		}
		
		while(role && !a.empty()){
			cout << a.back();
			a.pop_back();
		}
	};
	
	while(Q--){
		cin >> op;
		if(op == 1) rev ^= true;
		else{
			cin >> op;
			cin >> c;
			util(c, (op == 1));
		}
	}
	
	if(rev){
		print(rear, true);
		reverse(ALL(input));
		cout << input;
		print(front, false);
	}else{
		print(front, true);
		cout << input;
		print(rear, false);
	}
	
	
	return 0;
}
