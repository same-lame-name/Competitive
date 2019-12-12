#include <bits/stdc++.h>
using namespace std;

int main(){
	int TESTCASES; cin >> TESTCASES;
        while(TESTCASES--){
            vector<long long> nums(3);
            for(int itr = 0; itr < 3; ++itr) cin >> nums[itr];
            sort(nums.begin(), nums.end());
            long long pairWise = nums[2] - nums[0];
            if(pairWise <= 2) pairWise = 0;
            else pairWise -= 2;
            cout << 2 * pairWise << endl;
        }
    return 0;
}