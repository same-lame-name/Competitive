#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> numCount(5, 0);
    int totalTaxis = 0;
    for(int itr = 0; itr < N; ++itr){
        int curGroup; cin >> curGroup;
        numCount[curGroup]++;
    }
    int three_one = min(numCount[1], numCount[3]);
    numCount[1] -= three_one;
    int two_one = min(numCount[2] * 2, numCount[1]);
    numCount[1] -= two_one;
    int modTwo = numCount[2] - (two_one / 2 + (two_one % 2));
    numCount[2] -= modTwo / 2;
    numCount[1] = numCount[1] / 4 + (numCount[1] % 4 > 0);
    for(int ele : numCount) totalTaxis += ele;
    cout << totalTaxis << endl;
}