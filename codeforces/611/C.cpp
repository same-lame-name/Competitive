#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

	ll rowN, colN, qCount; cin >> rowN >> colN;
        vector<string> grid(rowN);
        for(int row = 0; row < rowN; ++row) cin >> grid[row];
        vector<vector<ll>> horWays(rowN + 1, vector<ll>(colN + 1, 0));
        vector<vector<ll>> verWays(rowN + 1, vector<ll>(colN + 1, 0));
        for(ll row = 1; row <= rowN; ++row){
            for(ll col = 1; col <= colN; ++col){
                horWays[row][col] = horWays[row - 1][col] 
                	            + horWays[row][col - 1]
                                    - horWays[row - 1][col - 1];
                verWays[row][col] = verWays[row - 1][col]
                	            + verWays[row][col - 1]
                                    - verWays[row - 1][col - 1];
                if(grid[row - 1][col - 1] == '.'){
                    if(col < colN && grid[row - 1][col] == '.') horWays[row][col]++;
                    if(row < rowN && grid[row][col - 1] == '.') verWays[row][col]++;
                }		
            }
        } 
        cin >> qCount;
        while(qCount--){
            ll bRow, bCol, tRow, tCol;
            cin >> tRow >> tCol >> bRow >> bCol;
            ll totalUnique = 0;
            totalUnique += (horWays[bRow][bCol - 1]
            		   + horWays[tRow - 1][tCol - 1]
                           - horWays[bRow][tCol - 1]
                           - horWays[tRow - 1][bCol - 1]);
            totalUnique += (verWays[bRow - 1][bCol]
            		   + verWays[tRow - 1][tCol - 1]
                           - verWays[bRow - 1][tCol - 1]
                           - verWays[tRow - 1][bCol]);
            cout << totalUnique << endl;
        }
        
       	return 0;
}