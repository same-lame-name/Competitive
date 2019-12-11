#include <bits/stdc++.h>
using namespace std;

int DFS(vector<string>& grid, int row, int col, vector<pair<int, int>>& covered){
    covered.push_back({row, col});
    grid[row][col] = '#';
    int wallsEnc = 0;
    int rowN = grid.size(), colN = grid[0].size();
    vector<pair<int, int>> directions ={{1, 0},{0, 1},{-1, 0},{0, -1}};
    for(pair<int, int> dir : directions){
        int nRow = row + dir.first;
        int nCol = col + dir.second;
        if(nRow >= 0 && nRow < rowN && nCol >= 0 && nCol < colN){
            if(grid[nRow][nCol] == '*'){
                wallsEnc++;
            } 
            else if(grid[nRow][nCol] == '.'){
                wallsEnc += DFS(grid, nRow, nCol, covered);
            }
        }
    } 
    return wallsEnc;
}

int main(){
    int rowN, colN, startN;
    cin >> rowN >> colN >> startN;
    vector<string> grid(rowN);
    for(int row = 0; row < rowN; ++row){
       	cin >> grid[row];
    }
    vector<vector<int>> prevResults(rowN, vector<int>(colN, -1));
    for(int itr = 0; itr < startN; ++itr){
        int row, col; cin >> row >> col;
        int wallPaintingC = 0;
        if(prevResults[row - 1][col - 1] != -1){
                wallPaintingC = prevResults[row - 1][col - 1];     
        }
        else if(grid[row - 1][col - 1] == '.'){
            vector<pair<int, int>> covered;
            wallPaintingC = DFS(grid, row - 1, col - 1, covered);
            for(auto ele : covered){
                int cRow = ele.first, cCol = ele.second;
                prevResults[cRow][cCol] = wallPaintingC;
            }
        }
        cout << wallPaintingC << endl;
    }
    return 0;
}