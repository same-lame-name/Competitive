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
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;

bool DFS(vector<int>& tag, vector<vector<int>>& adjList, int curN){
    int neighTag = tag[curN] ^ 1;
    for(int neighN : adjList[curN]){
        if(tag[neighN] == -1){
            tag[neighN] = neighTag;
            DFS(tag, adjList, neighN);
        }
        else if(tag[neighN] != neighTag) return false;
    }
    return true;
}

int main(){
    int N, M; cin >> N >> M;
    vector<vector<int>> adjList(N + 1);
    vector<int> tag(N + 1, -1);
    bool possible = true;
    REP(I, M){
        int oneVertex, secVertex;
        cin >> oneVertex >> secVertex;
        adjList[oneVertex].PB(secVertex);
        adjList[secVertex].PB(oneVertex);
    }
    REPP(nodeN, 1, N + 1){
        if(tag[nodeN] == -1)tag[nodeN] = 0;
        if(!DFS(tag, adjList, nodeN)){
            possible = false;
            break;
        };
    }
    if(!possible){
        cout << -1 << endl;
    }else{
        int oneTag = 0;
        REPP(nodeN, 1, N + 1){
            if(tag[nodeN] == 1) oneTag++;
        }
        int zeroTag = N - oneTag;
        cout << oneTag << endl;
        REPP(nodeN, 1, N + 1){
            if(tag[nodeN] == 1) cout << nodeN << " ";
        }
        cout << endl;
        cout << zeroTag << endl;
        REPP(nodeN, 1, N + 1){
            if(tag[nodeN] == 0) cout << nodeN << " ";
        }
        cout << endl;
    }
    return 0;
}
