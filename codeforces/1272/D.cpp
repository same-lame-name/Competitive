#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N, maxL = 1; cin >> N;
        vector<long long> nums(N);
        for(long long itr = 0; itr < N; ++itr) cin >> nums[itr];
        vector<vector<long long>> maxLen(N, vector<long long>(2, 1));
        maxLen[0][1] = 0;
        for(long long idx = 1; idx < N; ++idx){
            if(nums[idx - 1] < nums[idx]){
                maxLen[idx][0] = maxLen[idx - 1][0] + 1;
                maxLen[idx][1] = maxLen[idx - 1][1] + 1;
            }
            if(idx - 2 >= 0 && nums[idx - 2] < nums[idx]){
                maxLen[idx][1] = max(maxLen[idx][1], maxLen[idx - 2][0] + 1);
            }
            maxL = max({maxL, maxLen[idx][0], maxLen[idx][1]});
	}
        cout << maxL << endl;
        
    return 0;
}