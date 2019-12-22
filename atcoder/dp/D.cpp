#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	const ll INF = 1e9 + 5;
        ll N, W; cin >> N >> W;
        vector<ll> weights(N), value(N);
        for(ll rep = 0; rep < N; ++rep){
            cin >> weights[rep] >> value[rep];
        }
        vector<vector<ll>> maxValue(N, vector<ll>(W + 1, 0));
        for(ll weight = weights[0]; weight <= W; ++weight){
            maxValue[0][weight] = value[0];
        }
        for(ll itemN = 1; itemN < N; ++itemN){
            for(ll curW = 0; curW <= W; ++curW){
            	maxValue[itemN][curW] = maxValue[itemN - 1][curW];
                if(curW < weights[itemN]) continue;
             	maxValue[itemN][curW] = 
                        max(maxValue[itemN - 1][curW - weights[itemN]] + value[itemN],
                        maxValue[itemN][curW]);
            }
        }
        cout << maxValue[N - 1][W] << endl;
    	return 0;
}