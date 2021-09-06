#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

int a[20][20],dp[20][(1<<20)-1];
int n,t,cases=0;

int _dp(int i,int mask){
	if(__builtin_popcount(mask)==n)return 0;
	int &ans=dp[i][mask];
	if(ans!=-1)return ans;
	
	for(int j=0;j<n;++j){
		if(mask&(1<<j))continue;
		ans=max(ans,_dp(i+1,mask|(1<<j))+a[i][j]);
	}
	return ans;
}

signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>a[i][j];
		
		memset(dp,-1,sizeof(dp));
		cout<<"Case "<<++cases<<": "<<_dp(0,0)<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}