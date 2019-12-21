#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll N, a, b, c; cin >> N >> a >> b >> c;
        vector<ll> maxRibbon(N + 1, -1);
        maxRibbon[0] = 0;
        for(ll length = 0; length <= N; ++length){
            for(ll curCut : {a, b, c}){
                if(maxRibbon[length] >= 0 && length + curCut <= N){
                    maxRibbon[length + curCut] = max(maxRibbon[length + curCut],
                    				     1 + maxRibbon[length]);
                }
            }
        }
        cout << maxRibbon[N] << endl;
    	return 0;
}