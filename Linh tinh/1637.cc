#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e6+10;
int dp[N];
int n;

int _dp(int n){
	if(n==0)return 0;
	
	int &ans=dp[n];
	if(ans!=-1)return ans;
	vector<int> digits;
	int tmp=n;
	while(tmp){
		digits.pb(tmp%10);
		tmp/=10;
	}
	
	ans=1e9;
	for(int i:digits)ans=min(ans,1+_dp(n-i));
	return ans;
}

signed main(){
	cin>>n;
	memset(dp,-1,sizeof dp);
	cout<<_dp(n);
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}