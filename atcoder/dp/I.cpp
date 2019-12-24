#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N;
        vector<double> pHead(N + 1, 0.0);
        pHead[0] = 1;
        for(int curToss = 0; curToss < N; ++curToss){
            double headP; cin >> headP;
            for(int headC = curToss + 1; headC >= 0; --headC){
                pHead[headC] = (1 - headP) * pHead[headC]
                	    + (headP) * (headC > 0 ? pHead[headC - 1] : 0.0); 
            }
        }
        double totalP = 0.0;
        for(int headC = N / 2 + 1; headC <= N; ++headC) totalP += pHead[headC];
        cout << setprecision(10) << totalP << endl;
    	return 0;
}