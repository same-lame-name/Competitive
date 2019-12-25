#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define MP make_pair
#define PB push_back
#define F first
#define S second
typedef long long LL;
using namespace std;
const LL INF = 1e9 + 7;
inline int in() { int x; scanf("%d", &x); return x; }


int main(){
    DRII(appC, queryC);
    vector<queue<int>> appNoti(appC + 1);
    vector<bool> chrono(queryC + 1, false);
    int readC = 0, time = 0, nextTime = 1;
    while(queryC--){
        DRI(query);
        if(query == 1){
            DRI(appN);
            ++time;
            appNoti[appN].push(time);
        }else if(query == 2){
            DRI(appN);
            while(!appNoti[appN].empty()){
                int t = appNoti[appN].front(); appNoti[appN].pop();
                if(!chrono[t]) readC++;
                chrono[t] = true;
            }
        }else{
            DRI(topN);
            REPP(rep, nextTime, topN + 1){
                if(chrono[rep] == false){
                    chrono[rep] = true;
                    readC++;
                }
            }
            nextTime = max(nextTime, topN + 1);
        }
        cout << time - readC << endl;
    }
    return 0;
}
