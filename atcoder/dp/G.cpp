#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e12 + 5;


ll DFSutils(ll nodeN, vector<ll>&pathLen, vector<vector<ll>>& adjList){
    if(pathLen[nodeN] != -1) return pathLen[nodeN];
    ll curPath = -1;
    for(ll neighNode : adjList[nodeN]){
        curPath = max(curPath, 1 + DFSutils(neighNode, pathLen, adjList));
    }
    pathLen[nodeN] = curPath;
    return curPath;
}

int main(){
	ll N, M; cin >> N >> M;
        vector<vector<ll>> adjList(N + 1);
        vector<ll> pathLen(N + 1, -1);
        for(int nodeN = 1; nodeN <= N; ++nodeN) adjList[0].push_back(nodeN);
        for(ll rep = 0; rep < M; ++rep){
            ll from, to;
            cin >> from >> to;
            adjList[from].push_back(to);
        }
        ll maxPath = DFSutils(0, pathLen, adjList);
        cout << maxPath << endl;
    	return 0;
}