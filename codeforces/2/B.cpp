#include <bits/stdc++.h>
using namespace std;
#define vec  vector
#define pic pair<int, char>
#define f first
#define s second
#define INF 1e9 + 5
int main(){
	int N; cin >> N;
        vec<vec<vec<pic>>> miniMize(N + 1, vec<vec<pic>>(N + 1, vec<pic>(2, {INF, '#'})));
        miniMize[0][1][0].f = 0;
        miniMize[1][0][1].f = 0;
        int hasZero = 0;
        vec<int> minParameter = {2, 5};
        for(int row = 1; row <= N; ++row){
            for(int col = 1; col <= N; ++col){
                int curCell; cin >> curCell;
                if(curCell == 0) hasZero = col;
                for(int k = 0; k < 2; ++k){
                    int curCost = 0;
                    while(curCell && (curCell % minParameter[k] == 0)){
                        curCost++;
                        curCell /= minParameter[k];
                    }
                    if(miniMize[row - 1][col][k].f < miniMize[row][col -1][k].f){
                        miniMize[row][col][k].f = miniMize[row - 1][col][k].f;
                        miniMize[row][col][k].s = 'D';
                    }else{
                        miniMize[row][col][k].f = miniMize[row][col - 1][k].f;
                        miniMize[row][col][k].s = 'R';
                    }
                    miniMize[row][col][k].f += curCost;
                }
            }
        }
        int backIdx = -1, minZero = -1;
        if(miniMize[N][N][0].f < miniMize[N][N][1].f){
            backIdx = 0;
            minZero = miniMize[N][N][0].f;
        }
        else{
            backIdx = 1;
            minZero = miniMize[N][N][1].f;
        }
        string path = "";
        if(hasZero && minZero >= 1){
            for(int rep = 1; rep < hasZero; ++rep) path.push_back('R');
            for(int rep = 0; rep < N - 1; ++rep) path.push_back('D');
            for(int rep = hasZero; rep < N; ++rep) path.push_back('R');
            cout << 1 << endl << path << endl;
            return 0;
        }
        int row = N, col = N;
        while(miniMize[row][col][backIdx].s != '#'){
            if(row > 1 || col > 1) path.push_back(miniMize[row][col][backIdx].s);
            if(miniMize[row][col][backIdx].s == 'D') row--;
            else col--;
        }
        reverse(path.begin(), path.end());
        cout << minZero << endl << path << endl;
        return 0;
        
}