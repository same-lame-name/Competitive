#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll N; cin >> N;
        vector<ll> nums(N);
        for(ll &ele : nums) cin >> ele;
        sort(nums.begin(), nums.end());
        ll queryC; cin >> queryC;
        while(queryC--){
            ll curEle; cin >> curEle;
            auto itr = upper_bound(nums.begin(), nums.end(), curEle);
            cout << distance(nums.begin(), itr) << endl;
        }
    	return 0;
}