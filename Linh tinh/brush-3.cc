#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e2+10;
int a[N],dp[N][N];
int n,w,k,t,cases=0;

int _dp(int i,int cur){
	if(cur==0||i==n)return 0;
	int &ans=dp[i][cur];
	if(ans!=-1)return ans;
	
	ans=_dp(i+1,cur);
	int tot=0;
	for(int j=i;j<n&&a[j]<=a[i]+w;++j)++tot;
	
	return ans=max(ans,tot+_dp(i+tot,cur-1));
}

signed main(){
	cin>>t;
	while(t--){
		cin>>n>>w>>k;
		for(int i=0;i<n;++i){
			int x; cin>>x>>a[i];
		}
		sort(a,a+n);
		
		memset(dp,-1,sizeof(dp));
		cout<<"Case "<<++cases<<": "<<_dp(0,k)<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}