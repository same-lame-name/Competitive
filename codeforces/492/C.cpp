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
    long long examC, maxG, curAvg;
    cin >> examC >> maxG >> curAvg;
    vector<pair<LL, LL>> gradeCost(examC);
    LL curGrade = 0;
    REP(rep, examC){
        cin >> gradeCost[rep].second >> gradeCost[rep].first;
        curGrade += gradeCost[rep].second;
    }
    sort(ALL(gradeCost), [&](pair<LL, LL> a, pair<LL, LL> b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    LL reqGrade = examC * curAvg - curGrade;
    LL essayReq = 0;
    LL leftIdx = 0;
    while(reqGrade > 0 && leftIdx < examC){
        LL gradeAttained = gradeCost[leftIdx].second;
        LL essayCost = gradeCost[leftIdx].first;
        if(gradeAttained < maxG){
            LL canBeGained = (maxG - gradeAttained);
            canBeGained = min(canBeGained, reqGrade);
            essayReq += canBeGained * essayCost;
            reqGrade -= canBeGained;
        }
        leftIdx++;
    }
    cout << essayReq << endl;
    return 0;
}
