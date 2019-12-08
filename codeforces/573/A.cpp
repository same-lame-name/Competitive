#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N;
	vector<int> nums(N);
	for(int itr = 0; itr < N; ++itr) cin >> nums[itr];
	int lastNum = -1;
	bool ok = true;
	for(int ele : nums){
		while(ele % 2 == 0) ele /= 2;
		while(ele % 3 == 0) ele /= 3;
		if(lastNum != - 1 && ele != lastNum){
			ok = false;
			break;
		}
		lastNum = ele;
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}