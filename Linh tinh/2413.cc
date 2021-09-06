#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e6+10;
ll dp[N];
int n,t;

signed main(){
	dp[1]=2,dp[2]=8;
	for(int i=3;i<=N-10;++i){
		dp[i]=((dp[i-1]*6%MOD)-(dp[i-2]*7%MOD)+MOD)%MOD;
	}
	
	cin>>t;
	while(t--){
		cin>>n;
		cout<<dp[n]<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}