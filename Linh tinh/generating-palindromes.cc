#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e2+10;
string s;
int dp[N][N];
int t,cases=0;

int _dp(int l,int r){
	if(l>=r)return 0;
	int &ans=dp[l][r];
	if(ans!=-1)return ans;
	
	if(s[l]==s[r])ans=_dp(l+1,r-1);
	else ans=1+min(_dp(l+1,r),_dp(l,r-1));
	
	return ans;
}

signed main(){
	cin>>t;
	while(t--){
		cin>>s;
		memset(dp,-1,sizeof(dp));
		cout<<"Case "<<++cases<<": "<<_dp(0,(int)s.size()-1)<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}