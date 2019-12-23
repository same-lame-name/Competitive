#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e12 + 5;

int main(){
	ll N, W, maxGain = 0, maxValue = 0;
        cin >> N >> W;
        vector<ll> weights(N), values(N), maxVal(N);
        for(ll rep = 0; rep < N; ++rep){
            cin >> weights[rep] >> values[rep];
            maxValue += values[rep];
            maxVal[rep] = maxValue;
        }
        vector<ll> minWeights(maxValue + 1, INF);
        minWeights[0] = 0;
        for(ll itemN = 0; itemN < N; ++itemN){
            ll maxLimit = maxVal[itemN];
            for(ll value = maxLimit; value >= values[itemN]; --value){
                minWeights[value] = min(minWeights[value],
                		minWeights[value - values[itemN]] + weights[itemN]);
            } 
        }
        for(ll value = 0; value <= maxValue; ++value){
            if(minWeights[value] <= W) maxGain = value;
        }
        cout << maxGain << endl;
    	return 0;
}