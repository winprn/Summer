#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=5e3+10;
ll a[N],dp[N][N];
ll sum=0;
int n;

ll _dp(int l,int r){
	if(l==r)return a[l];
	
	ll &ans=dp[l][r];
	if(ans!=-1)return ans;
	
	ans=max(a[l]-_dp(l+1,r),a[r]-_dp(l,r-1));
	return ans;
}

signed main(){
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i],sum+=a[i];
	
	memset(dp,-1,sizeof dp);
	cout<<(sum+_dp(0,n-1))/2;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}