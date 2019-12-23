#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e12 + 5, mod = 1e9 + 7;

int main(){
	ll rowN, colN; cin >> rowN >> colN;
        vector<string> grid(rowN);
        for(int rep = 0; rep < rowN; ++rep){
            cin >> grid[rep];
        }
        vector<vector<ll>> ways(rowN + 1, vector<ll>(colN + 1, 0));
        ways[1][1] = 1;
        for(ll row = 1; row <= rowN; ++row){
            for(ll col = 1; col <= colN; ++col){
            	if(grid[row - 1][col - 1] != '#'){
                   ways[row][col] = (ways[row][col] + ways[row - 1][col]) % mod;
                   ways[row][col] = (ways[row][col] + ways[row][col - 1]) % mod;
                }
            }
        }
        cout << ways[rowN][colN] << endl;
    	return 0;
}