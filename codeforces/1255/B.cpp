#include <bits/stdc++.h>
using namespace std;

int main(){
    int TESTCASES; cin >> TESTCASES;
    while(TESTCASES--){
        int vertexC, edgeC;
        cin >> vertexC >> edgeC;
        long long sumWeight = 0;
        int leastW = INT_MAX - 5, secLeastW = INT_MAX;
        int leastV = -1, secLeastV = -1;
        for(int itr = 0; itr < vertexC; ++itr){
       	    int weights; cin >> weights;
            sumWeight += weights;
            if(weights < leastW){
            	secLeastV = leastV;
            	leastV = itr + 1;
                secLeastW = leastW;
                leastW = weights;
            }
            else if(weights < secLeastW){
              secLeastV = itr + 1;
              secLeastW = weights;  
            } 
     	}
        if(edgeC < vertexC || vertexC == 2){
            cout << -1 << endl;
            continue;
        }
        long long minCost = 2 * sumWeight;
        if(edgeC > vertexC) minCost += (edgeC - vertexC) * (leastW + secLeastW);
        cout << minCost << endl;
        for(int itr = 1; itr <= vertexC; ++itr){
            cout << itr << " " << (itr + 1 > vertexC ? 1 : itr + 1) << endl;
        }
        for(int itr = 0; itr < (edgeC - vertexC); ++itr){
            cout << leastV << " " << secLeastV << endl;
        }
    }
    return 0;
}