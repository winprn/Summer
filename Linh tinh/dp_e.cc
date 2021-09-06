#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e5+10;
ll w[105],v[105],dp[105][N];
ll tot=0;
int n,W;

ll _dp(int i,int cn){
	if(i==0){
		if(cn!=0)return 1e18;
		return 0;
	}
	ll &ans=dp[i][cn];
	if(ans!=-1)return ans;
	
	return ans=min(_dp(i-1,cn-v[i])+w[i],_dp(i-1,cn));
}

signed main(){
	cin>>n>>W;
	for(int i=1;i<=n;++i)cin>>w[i]>>v[i],tot+=v[i];
	
	memset(dp,-1,sizeof dp);
	dp[1][0]=0;
	dp[1][v[1]]=w[1];
	for(int i=tot;i>0;--i){
		if(_dp(n,i)<=W){
			cout<<i;
			break;
		}
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}