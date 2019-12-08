#include <bits/stdc++.h>
using namespace std;

int main(){
    int TESTCASES; cin >> TESTCASES;
    while(TESTCASES--){
        int rCount, gCount, bCount;
        cin >> rCount >> gCount >> bCount;
        int maxCandies = 0;
        if(rCount <= gCount + bCount){
            int greaterC = max(gCount, bCount), lesserC = min(gCount, bCount);
            int curCandies = rCount;
            int _rCount = rCount - (greaterC - lesserC);
            _rCount = _rCount / 2 + (_rCount % 2);
            _rCount = max(_rCount, 0);
            curCandies += (lesserC - _rCount);
            maxCandies = max(maxCandies, curCandies);
        }
        if(bCount <= gCount + rCount){
            int greaterC = max(gCount, rCount), lesserC = min(gCount, rCount);
            int curCandies = bCount;
            int _bCount = bCount - (greaterC - lesserC);
            _bCount = _bCount / 2 + (_bCount % 2);
            _bCount = max(_bCount, 0);
            curCandies += (lesserC - _bCount);
            maxCandies = max(maxCandies, curCandies);
        }
        if(gCount <= rCount + bCount){
            int greaterC = max(rCount, bCount), lesserC = min(rCount, bCount);
            int curCandies = gCount;
            int _gCount = gCount - (greaterC - lesserC);
            _gCount = _gCount / 2 + (_gCount % 2);
            _gCount = max(_gCount, 0);
            curCandies += (lesserC - _gCount);
            maxCandies = max(maxCandies, curCandies);
        }
        cout << maxCandies << endl;
    }
    return 0;
}