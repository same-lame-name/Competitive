#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll N; cin >> N;
        ll maxSub = 0, lastEle = INT_MIN, curLen = 0, curEle;
        for(int rep = 0; rep < N; ++rep){
            cin >> curEle;
            if(curEle >= lastEle){
                curLen++;
            }
            else{
                curLen = 1;
            }
            maxSub = max(maxSub, curLen);
            lastEle = curEle;
        }
        cout << maxSub << endl;
    	return 0;
}