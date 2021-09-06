#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=3e3+10;
string s,t;
int dp[N][N];

int _dp(int n,int m){
	if(n<=0||m<=0)return 0;
	int &ans=dp[n][m];
	if(ans!=-1)return ans;
	
	for(int i=1;i<m;++i){
		if(s[n]==t[m])ans=1+_dp(n-1,i);
		else ans=max(_dp(n-1,i),_dp(n,i-1));
	}
	return ans;
}

signed main(){
	cin>>s>>t;
	s=" "+s,t=" "+t;
	memset(dp,-1,sizeof dp);
	cout<<_dp((int)s.size()-1,(int)t.size());
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}