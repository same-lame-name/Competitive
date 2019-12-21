#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll N; cin >> N;
        map<ll, ll> freqCount;
        for(ll rep = 0; rep < N; ++rep){
            ll curEle; cin >> curEle;
            freqCount[curEle] += curEle;
        }
        ll prevInc = 0, prevNonInc = 0, prevEle = -1;
        for(auto ele : freqCount){
            ll curEle = ele.first, value = ele.second;
            ll maxNonInc = max(prevInc, prevNonInc);
            ll maxInc = value + max(prevNonInc, (prevEle != curEle - 1 ? prevInc : 0));
            prevEle = curEle;
            prevInc = maxInc;
            prevNonInc = maxNonInc;
        }
        cout << max(prevInc, prevNonInc) << endl;
    	return 0;
}