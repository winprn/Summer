#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

string s,t;
ll dp[35][35];
int dp1[35][35];
int ts,cases=0;

int _dp1(int i,int j){
	if(i==0)return j;
	if(j==0)return i;
	int &ans=dp1[i][j];
	if(ans!=-1)return ans;
	
	if(s[i]==t[j]){
		ans=1+_dp1(i-1,j-1);
	}else{
		ans=1+min(_dp1(i,j-1),_dp1(i-1,j));
	}
	
	return ans;
}

ll _dp(int i,int j){
	if(i==0||j==0)return 1;
	ll &ans=dp[i][j];
	if(ans!=-1)return ans;
	
	if(s[i]==t[j])ans=_dp(i-1,j-1);
	else{
		if(dp1[i-1][j]==dp1[i][j-1])ans=_dp(i-1,j)+_dp(i,j-1);
		else ans=min(_dp(i-1,j),_dp(i,j-1));
	}
	
	return ans;
}

signed main(){
	cin>>ts;
	while(ts--){
		cin>>s>>t;
		s=" "+s,t=" "+t;
		int n=(int)s.size(),m=(int)t.size();
		memset(dp1,-1,sizeof(dp1));
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<=33;++i)dp1[0][i]=dp1[i][0]=i,dp[i][0]=dp[0][i]=1;
		cout<<"Case "<<++cases<<": ";
		cout<<_dp1(n-1,m-1)<<' ';
		cout<<_dp(n-1,m-1)<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}