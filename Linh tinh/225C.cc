#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e3+10;
int dp[2][N],num[2][N],pr[2][N];
int n,m,x,y;

int _dp(bool t,int i){
	if(i==0)return 0;
	int &ans=dp[t][i];
	if(ans!=-1)return ans;
	
	ans=1e9;
	for(int j=max(i-y,0);j<=i-x;++j){
		ans=min(ans,_dp(1-t,j)+pr[1-t][i]-pr[1-t][j]);
	}
	return ans;
}

signed main(){
	cin>>n>>m>>x>>y;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			char x; cin>>x;
			num[1][j]+=(x=='#');
			num[0][j]+=(x=='.');
		}
	}
	
	//for(int i=0;i<m;++i)cout<<num[1][i]<<' '<<num[0][i]<<endl;
	
	pr[0][0]=num[0][0],pr[1][0]=num[1][0];
	for(int i=0;i<m;++i){
		pr[0][i+1]=num[0][i]+pr[0][i];
		pr[1][i+1]=num[1][i]+pr[1][i];
	}
	
	memset(dp,-1,sizeof dp);
	cout<<min(_dp(0,m),_dp(1,m))<<endl;
	//for(int i=x;i<=y;++i)cout<<dp[0][i]<<' '<<dp[1][i]<<endl;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}