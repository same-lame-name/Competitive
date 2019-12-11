#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    int qCount; cin >> qCount;
    while(qCount--){
        int startIdx, endIdx, shiftC;
        cin >> startIdx >> endIdx >> shiftC;
        int lenS = endIdx - startIdx + 1;
        shiftC = shiftC % lenS;
        string helper = S.substr(startIdx - 1, lenS);
        for(int itr = 0, pIdx = (lenS - shiftC) % lenS; itr < lenS; ++itr){
            S[startIdx - 1 + itr] = helper[pIdx];
            pIdx = (pIdx + 1) % lenS;
        }
    }
    cout << S << endl;
    return 0;
}