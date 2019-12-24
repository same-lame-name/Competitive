#include <bits/stdc++.h>
using namespace std;
#define vec vector
using ll = long long;
#define INF 1e9 + 5

int main(){
	ll N, fSum = 0; cin >> N;
        vec<ll> prefixS(N, 0);
        for(ll rep = 0; rep < N; ++rep){
            ll curEle; cin >> curEle;
            fSum += curEle;
            prefixS[rep] = fSum;
        }
        if(fSum % 3){
            cout << 0 << endl;
            return 0;
        } 
        ll reqSum = fSum / 3, totalWays = 0;
        vec<ll> suffixReq(N + 1, 0);
        for(ll idx = N - 1; idx >= 0; --idx){
            ll curSuffix = fSum - (idx > 0 ? prefixS[idx - 1] : 0);
            suffixReq[idx] = suffixReq[idx + 1] + (curSuffix == reqSum);
        }
        for(ll idx = 0; idx < N - 2; ++idx){
            if(prefixS[idx] == reqSum){
                totalWays += suffixReq[idx + 2];
            }
        }
        cout << totalWays << endl;
        
        
        
        return 0;
        
}