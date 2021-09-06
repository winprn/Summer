#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=5e2+10;
int dp[N][N];
int n,m;

int _dp(int x,int y){
	if(x==y)return 0;
	if(x<y)swap(x,y);
	
	int &ans=dp[x][y];
	if(ans!=-1)return ans;
	ans=1e9;
	
	for(int i=1;i<x;++i){
		if(y>i)ans=min(ans,1+_dp(y-i,x)+_dp(i,x));
		ans=min(ans,1+_dp(y,x-i)+_dp(y,i));
	}
	return ans;
}

signed main(){
	cin>>n>>m;
	memset(dp,-1,sizeof dp);
	cout<<_dp(n,m);
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}