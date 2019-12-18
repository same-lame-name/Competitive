#include <bits/stdc++.h>
using namespace std;


int main(){
	int N, M, plainD, plainRev;
        cin >> N >> M >> plainD >> plainRev;
        vector<int> maxRev(N + 1, 0);
        for(int doughA = plainD; doughA <= N; ++doughA){
            maxRev[doughA] = (doughA / plainD) * plainRev;
        }
   	vector<int> doughCost(M), revenue(M), maxUse(M);
        for(int rep = 0; rep < M; ++rep){
            int stuffAvail, stuffReq, doughC, money;
            cin >> stuffAvail >> stuffReq >> doughC >> money;
            doughCost[rep] = doughC; revenue[rep] = money;
            maxUse[rep] = stuffAvail / stuffReq;
        } 
        for(int stuffT = 0; stuffT < M; ++stuffT){
            for(int rep = 0; rep < maxUse[stuffT]; ++rep){
                int doughC = doughCost[stuffT];
                int curValue = revenue[stuffT];
                for(int doughA = N; doughA >= doughC; --doughA){
                    maxRev[doughA] = max(maxRev[doughA],
                    			 curValue + maxRev[doughA - doughC]);
                }
            }
        }   
        cout << maxRev[N] << endl;
        return 0;
}