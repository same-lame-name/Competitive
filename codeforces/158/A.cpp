#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, k; cin >> N >> k;
    vector<int> nums;
    for(int itr = 0; itr < N; ++itr){
        int curNum; cin >> curNum;
        if(curNum > 0) nums.push_back(curNum);
        else break;
    }
    int M = nums.size();
    if(k > M) cout << M << endl;
    else{
        int threshScore = nums[k - 1];
    	auto itr = upper_bound(nums.begin(), nums.end(), threshScore, greater<int>());
    	cout << distance(nums.begin(), itr);
    }
    return 0;
}