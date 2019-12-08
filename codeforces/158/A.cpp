#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, k; cin >> N >> k;
    int curRank = 0, totalTimes = 0, kthEle = -1;
    while(curRank < k){
        int curNum; cin >> curNum;
        if(curNum <= 0) break;
        curRank++;
        if(curRank == k) kthEle = curNum;
      	while(totalTimes < N && curRank == k && curNum == kthEle){
           totalTimes++;
           cin >> curNum;  
        }
        if(curRank < k) totalTimes++;
    }
    cout << totalTimes << endl;
    return 0;
}