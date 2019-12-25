#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    string number; cin >> number;
    vector<int> digitC(10, 0);
    for(int idx = 0; idx < N; ++idx){
        int curDigit = number[idx] - '0';
        digitC[curDigit]++;
    }
    digitC[2] += 2*digitC[4] + 3*digitC[8] + digitC[9];
    digitC[3] += digitC[4] + 2*digitC[9] + digitC[6];
    digitC[5] += digitC[6];
    digitC[7] += digitC[8] + digitC[9];
    string maxNum = "";
    for(int digit : {7, 5, 3, 2}){
        for(int rep = 0; rep < digitC[digit]; ++rep){
            maxNum.push_back('0' + digit);
        }
    }      
    cout << maxNum << endl;  
    return 0;
}
