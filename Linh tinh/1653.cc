#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

pair<int,int> dp[1<<20];
int a[25];
int n,m;

signed main(){
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	
	dp[0]={0,0};
	for(int mask=1;mask<(1<<n);++mask){
		dp[mask]={n,0};
		for(int i=0;i<n;++i){
			if(mask&(1<<i)){
				auto tmp=dp[mask-(1<<i)];
				if(tmp.se+a[i]<=m){
					tmp.se+=a[i];
				}else{
					tmp.fi++;
					tmp.se=a[i];
				}
				
				dp[mask]=min(dp[mask],tmp);
			}
		}
	}
	cout<<dp[(1<<n)-1].fi+1;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}