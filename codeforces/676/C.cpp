#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll N, allowed; cin >> N >> allowed;
        string curS; cin >> curS;
        vector<ll> freqCount(2, 0);
        ll leftIdx = 0, rightIdx = 0, maxLen = 0;
        while(rightIdx < N){
            freqCount[curS[rightIdx] - 'a']++;
            while(min(freqCount[0], freqCount[1]) > allowed && leftIdx <= rightIdx){
                freqCount[curS[leftIdx] - 'a']--;
                leftIdx++;
            }
            maxLen = max(maxLen, rightIdx - leftIdx + 1);
            rightIdx++;
        }
        cout << maxLen << endl;
        return 0;
}