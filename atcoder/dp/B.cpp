#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	const ll INF = 1e9 + 5;
	ll N, k; cin >> N >> k;
        vector<ll> heights(N), minCost(N, INF);
        minCost[0] = 0;
        for(ll &ele : heights) cin >> ele;
        minCost[0] = 0;
        for(ll place = 0; place < N; ++place){
            for(int jump = 1; jump <= k; ++jump){
                if(place + jump < N){
                   minCost[place + jump] = min(minCost[place + jump],
                    			  minCost[place] 
                                          + abs(heights[place] - heights[place + jump]));
                }
            }
        }
        cout << minCost[N - 1] << endl;
    	return 0;
}