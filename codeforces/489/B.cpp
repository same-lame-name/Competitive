#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll N, M;
        cin >> N;
        vector<ll> boyS(N);
        for(ll &ele : boyS) cin >> ele;
        cin >> M;
        vector<ll> girlS(M);
        for(ll &ele : girlS) cin >> ele;
        sort(boyS.begin(), boyS.end());
        sort(girlS.begin(), girlS.end());
        ll boyItr = 0, girlItr = 0, pairFormed = 0;
        while(boyItr < N && girlItr < M){
            if(abs(boyS[boyItr] - girlS[girlItr]) <= 1){
                pairFormed++;
                boyItr++;
                girlItr++;
            }
            else if(boyS[boyItr] > girlS[girlItr]) girlItr++;
            else boyItr++;
        }
        cout << pairFormed << endl;
    	return 0;
}