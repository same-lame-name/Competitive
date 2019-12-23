#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e12 + 5;


int main(){
	string text1, text2;
        cin >> text1 >> text2;
        int N = text1.size(), M = text2.size();
        vector<vector<int>> LCS(N + 1, vector<int>(M + 1, 0));
        for(int onePos = 1; onePos <= N; ++onePos){
            for(int twoPos = 1; twoPos <= M; ++twoPos){
                if(text1[onePos - 1] == text2[twoPos - 1]){
                    LCS[onePos][twoPos] = 1 + LCS[onePos - 1][twoPos - 1];
                }
                else{
                    LCS[onePos][twoPos] = max(LCS[onePos - 1][twoPos],
                    			      LCS[onePos][twoPos - 1]);
                }
            }
        }
        string maxLCS = "";
        int onePos = N, twoPos = M;
       	while(LCS[onePos][twoPos] > 0){
               if(text1[onePos - 1] == text2[twoPos - 1]){
                   maxLCS.push_back(text1[onePos - 1]);
                   onePos--;
                   twoPos--;
               }else if(LCS[onePos - 1][twoPos] == LCS[onePos][twoPos]){
                   onePos--;
               }else{
                   twoPos--;
               }
        }
        reverse(maxLCS.begin(), maxLCS.end());
        cout << maxLCS << endl;
    	return 0;
}