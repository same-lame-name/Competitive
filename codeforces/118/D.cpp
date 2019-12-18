#include <bits/stdc++.h>
using namespace std;
#define megaV vector<vector<vector<vector<int>>>>
int N, M, consN, consM, mod = 1e8;

int DPutils(megaV& memo, int Nused, int curL, int cMused, int cNused){
    int lenReq = N + M - curL;
    if(lenReq == 0) return 1;
    int Mused = curL - Nused;
    int curWay = 0;
    if(memo[Nused][curL][cMused][cNused] != -1) return memo[Nused][curL][cMused][cNused];
    if(Mused + 1 <= M && cMused + 1 <= consM){
        curWay = (curWay + DPutils(memo, Nused, curL + 1, cMused + 1, 0)) % mod;
    }
    if(Nused + 1 <= N && cNused + 1 <= consN){
        curWay = (curWay + DPutils(memo, Nused + 1, curL + 1, 0, cNused + 1)) % mod;
    }
    memo[Nused][curL][cMused][cNused] = curWay;
    return curWay;
}

int main(){
	
        cin >> N >> M >> consN >> consM;
        megaV memo(N + 1,
        	  vector<vector<vector<int>>>(N + M + 1,
                  vector<vector<int>>(consM + 1,
                  vector<int>(consN + 1, -1))));
        int modWays = DPutils(memo, 0, 0, 0, 0);
        cout << modWays << endl;
        return 0;
}