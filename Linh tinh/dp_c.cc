#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e5+10;
int a[N],b[N],c[N],dp[N][3];
int n;

int _dp(int i,int lst){
	if(i<=0)return 0;
	int &ans=dp[i][lst];
	if(ans!=-1)return ans;
	
	if(lst==0)ans=max(b[i]+_dp(i-1,1),c[i]+_dp(i-1,2));
	if(lst==1)ans=max(a[i]+_dp(i-1,0),c[i]+_dp(i-1,2));
	if(lst==2)ans=max(a[i]+_dp(i-1,0),b[i]+_dp(i-1,1));
	return ans;
}

signed main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i]>>b[i]>>c[i];
	
	memset(dp,-1,sizeof dp);
	_dp(n,0),_dp(n,1),_dp(n,2);
	cout<<max({dp[n][0],dp[n][1],dp[n][2]});
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}