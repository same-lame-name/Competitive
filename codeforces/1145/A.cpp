#include <bits/stdc++.h>
using namespace std;


int main(){
    int N; cin >> N;
    vector<int> nums(N);
    for(int itr = 0; itr < N; ++itr) cin >> nums[itr];
    queue<pair<int, int>> BFS;
    BFS.push({0, N - 1});
    int maxLen = 0;
    while(!BFS.empty()){
        pair<int, int> cRange = BFS.front(); BFS.pop();
        int startIdx = cRange.first, endIdx = cRange.second;
        int curLen = endIdx - startIdx + 1;
        bool ok = true;
        for(int idx = startIdx + 1; idx <= endIdx; ++idx){
            if(nums[idx] < nums[idx - 1]){
                ok = false;
                break;
            }
        }
        if(ok){
            maxLen = curLen;
            break;
        }
        int break_one = startIdx + curLen / 2 - 1;
        BFS.push({startIdx, break_one});
        BFS.push({break_one + 1, endIdx});
    }
    cout << maxLen << endl;
    return 0;
}