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
	int k, s, count = 0, add = 1;
	cin >> k >> s;
	vector<int> mul = {1, 3, 3, 1};
	for(int itr = 0; itr < 4; ++itr){
		if(s < itr * (k + 1)) break;
		count += add * mul[itr] * (s - itr * (k + 1) + 2) * (s - itr * (k + 1) + 1) / 2;
		add *= -1;
	}
	
	cout << count << "\n";
	
}
