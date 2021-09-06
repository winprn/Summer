#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int num[]={6,2,5,5,4,5,6,3,7,6};
const int N=1e5+10;
vector<int> a;
ll dp[N],trace[N];
int n,m,mn=1e9;

ll _dp(int x){	
	ll &ans=dp[x];
	if(ans!=-1)return ans;
	
	ll mx=-1e18;
	for(int i:a){
		if(x==n&&i==0&&n!=num[i])continue;
		if(x>=num[i]){
			if(1+_dp(x-num[i])>=mx){
				mx=1+_dp(x-num[i]);
				trace[x]=i;
			}
		}
	}
	return ans=mx;
}

signed main(){
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int x; cin>>x;
		a.pb(x);
		mn=min(mn,num[x]);
	}
	
	memset(dp,-1,sizeof dp);
	dp[0]=0;
	for(int i=1;i<mn;++i)dp[i]=-1e9;
	_dp(n);
	
	vector<int> ans;
	//cout<<trace[n-num[7]]<<endl;
	//for(int i=1;i<=n;++i)if(trace[i]==5)cout<<i<<endl;
	while(n){
		ans.pb(trace[n]);
		n-=num[trace[n]];
	}
	
	sort(ans.rbegin(),ans.rend());
	if(ans[0]==0)cout<<0;
	else for(int i:ans)cout<<i;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}