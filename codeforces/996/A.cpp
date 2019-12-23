#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll N; cin >> N;
        ll curChange = 0;
        for(ll coin : {100, 20, 10, 5, 1}){
            curChange  += N / coin;
            N = N % coin;
        }
        cout << curChange << endl;
    	return 0;
}