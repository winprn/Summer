#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=5e3+10;
string s,t;
int dp[N][N];

signed main(){
	cin>>s>>t;
	int n=(int)s.size(),m=(int)t.size();
	
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(i)dp[i][j]=min(dp[i][j],1+dp[i-1][j]);
			if(j)dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
			if(i&&j)dp[i][j]=min(dp[i][j],(s[i-1]!=t[j-1])+dp[i-1][j-1]);
		}
	}	
	cout<<dp[n][m];
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}