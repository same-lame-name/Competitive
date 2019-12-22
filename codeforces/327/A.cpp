#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll N; cin >> N;
        vector<ll> isOne(N);
        for(ll &ele : isOne) cin >> ele;
        ll maxLen = -1, oneCount = 0;
        ll curPrefix;
        for(ll idx = 0; idx < N; ++idx){
            ll curEle = (isOne[idx] ? -1 : 1);
            oneCount += isOne[idx];
            if(idx == 0) curPrefix = curEle;
            else{
                curPrefix = max(curPrefix + curEle, curEle);
            }
            maxLen = max(maxLen, curPrefix);
        }
        cout << oneCount + maxLen << endl;
    	return 0;
}