#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e3+10;
int dp[N][N];
char a[N][N];
int n;

int _dp(int i,int j){
	if(i<0||j<0)return 0;
	if(a[i][j]=='*')return 0;
	if(i==0&&j==0)return 1;
	
	int &ans=dp[i][j];
	if(ans!=-1)return ans;
	ans=_dp(i-1,j)+_dp(i,j-1);
	ans%=MOD;
	
	return ans;
}

signed main(){
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)cin>>a[i][j];
	}
	
	memset(dp,-1,sizeof dp);
	cout<<_dp(n-1,n-1);
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}