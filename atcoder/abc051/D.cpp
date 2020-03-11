#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define ALLR(X) (X).rbegin(), (X).rend()
#define angle(a) (atan2((a).imag(), (a).real()))
#define vec(a, b) ((b) - (a))
#define length(a) (hypot((a).imag(), (a).real()))
#define dot(a, b) ((conj(a) * (b)).real())
#define cross(a, b) ((conj(a) * (b)).imag())
#define lengthSqr(p) dot(p, p)
#define rotateO(p, ang) ((p) * exp(point(0, ang)))
#define rotateA(p, ang, about) (rotateO(vec(about, p), ang) + about)
#define reflectO(v, m) (conj((v) / (m)) * (m))
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define X() real()
#define Y() imag()
using namespace std;
 
template<class T> void max_self(T & a, const T & b) { if(a < b) a = b; }
template<class T> void min_self(T & a, const T & b) { if(a > b) a = b; }
typedef long long LL;
typedef complex<double> point;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);


int main(){
	FAST_IO
	int N, M, count = 0; cin >> N >> M;
	
	vector<vector<int>> distance(N + 1, vector<int>(N + 1, INF));
	vector<int> one(M + 1), two(M + 1), weight(M + 1);
	
	for(int node = 1; node <= N; ++node) distance[node][node] = 0;
	
	for(int rep = 1; rep <= M; ++rep){
		int from, to, w; 
		cin >> from >> to >> w;
		distance[from][to] = distance[to][from] = w;
		one[rep] = from; two[rep] = to; weight[rep] = w;
	}
	
	for(int via = 1; via <= N; ++via){
		for(int from = 1; from <= N; ++from){
			for(int to = 1; to <= N; ++to){
				if(distance[from][via] == INF || distance[via][to] == INF) continue;
				if(distance[from][to] > distance[from][via] + distance[via][to]){
					distance[from][to] = distance[from][via] + distance[via][to];
				}
			}
		}
	}
	
	auto check = [&](int via, int edge){
		int from = one[edge], to = two[edge], w = weight[edge];
		if(abs(distance[via][from] - distance[via][to]) == w) return true;
		return false;
	};
	
	for(int edge = 1; edge <= M; ++edge){
		bool contained = false;
		for(int j = 1; j <= N; ++j){
			if(check(j, edge)){
				contained = true;
				break;
			}
		}
		if(!contained) count++;
	}
	
	cout << count << "\n";
}
