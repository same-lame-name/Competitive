#include <bits/stdc++.h>
using namespace std;

int main(){
    int TESTCASES; cin >> TESTCASES;
    while(TESTCASES--){
        long long N; cin >> N;
        long long allSum = (N + 1) * N / 2;
        long long powOfTwoN = log2(N);
        long long powOfTwoSum = pow(2, powOfTwoN + 1) - 1;
        allSum -= (2 * powOfTwoSum);
        cout << allSum << endl;
    }
    return 0;
}