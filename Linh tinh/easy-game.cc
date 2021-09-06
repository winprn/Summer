#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e2+10;
int a[N],dp[N][N];
int n,t,cases=0;

int _dp(int l,int r){
	if(l>r)return 0;
	if(l==r)return a[l];
	int &ans=dp[l][r];
	if(ans!=-1e9)return ans;
	
	int sum=0;
	for(int i=l;i<=r;++i){
		sum+=a[i];
		ans=max(ans,sum-_dp(i+1,r));
	}
	sum=0;
	for(int i=r;i>=l;--i){
		sum+=a[i];
		ans=max(ans,sum-_dp(l,i-1));
	}
	return ans;
}

signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		
		for(int i=0;i<n;++i)for(int j=0;j<n;++j)dp[i][j]=-1e9;
		cout<<"Case "<<++cases<<": "<<_dp(0,n-1)<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}