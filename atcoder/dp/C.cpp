#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	const ll INF = 1e9 + 5;
	ll N; cin >> N;
        vector<vector<ll>> choices(N, vector<ll>(3));
        for(ll rep = 0; rep < N; ++rep){
            cin >> choices[rep][0];
            cin >> choices[rep][1];
            cin >> choices[rep][2];
        }
        vector<vector<ll>> maxGain(N, vector<ll>(3, -INF));
        maxGain[0][0] = choices[0][0];
        maxGain[0][1] = choices[0][1];
        maxGain[0][2] = choices[0][2];
        for(ll day = 1; day < N; ++day){
            for(ll choice = 0; choice < 3; ++choice){
                for(ll pChoice = 0; pChoice < 3; ++pChoice){
                    if(choice == pChoice) continue;
                    maxGain[day][choice] = max(maxGain[day][choice],
                    		      maxGain[day - 1][pChoice] + choices[day][choice]);
                }
            }
        }
        cout << max({maxGain[N - 1][0], maxGain[N - 1][1], maxGain[N - 1][2]}) << endl;
    	return 0;
}