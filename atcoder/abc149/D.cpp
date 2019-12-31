#include<bits/stdc++.h>
using namespace std;
#define int 		  long long
#define	pb 			  push_back
#define all(a)		  (a).begin(),(a).end()
#define sz(x)		  (int)x.size()
#define endl	 	  "\n"
#define inf 		  1000000007
#define FOR(i, a, b)  for(int i=a; i<b; i++)
int dp[100011] = {0};
int r, p, s;
int fu(char st){
	if(st=='r')return p;
	else if(st=='p') return s;
	else return r;
}
void solve(){
	int n, k, res=0;
	cin>>n>>k;
	cin>>r>>s>>p;
	string g;
	cin>>g;
	FOR(i, 0, k){
		res+=fu(g[i]);
		dp[i] = res;
	}
	//cout<<dp[k-1]<<endl;
	FOR(i, k, sz(g)){
		if(g[i-k]==g[i]){

			dp[i] = dp[i-1];
			g[i]='0';
		}
		else{
			dp[i] = dp[i-1]+fu(g[i]);
		}
		//cout<<dp[i]<<" ";
	}
	cout<<dp[n-1];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	//cin>>t;
	FOR(i, 1, t+1){	
	//	cout<<"Case #"<<i<<":"<<endl;
		solve();
	}
	return 0;
 
}
