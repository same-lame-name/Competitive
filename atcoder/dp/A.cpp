#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll N, M = 1e9 + 7; cin >> N;
        vector<ll> heights(N), minCost(N);
        for(ll &ele : heights) cin >> ele;
        minCost[0] = 0;
        for(ll place = 1; place < N; ++place){
            ll prevMin = M;
            if(place - 2 >= 0){
                prevMin = min(prevMin,
        		  minCost[place - 2] + abs(heights[place - 2] - heights[place]));
            }
            prevMin = min(prevMin,
            	      minCost[place - 1] + abs(heights[place - 1] - heights[place]));
	    minCost[place] = prevMin;            
        }
        cout << minCost[N - 1] << endl;
    	return 0;
}