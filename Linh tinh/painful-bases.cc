#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=17;
string digs;
ll dp[(1<<N)][20];
int base,k,n,t,cases=0;

signed main(){
	cin>>t;
	while(t--){
		cin>>base>>k>>digs;
		int len=(int)digs.size();
		
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int mask=0;mask<(1<<len);++mask){
			for(int i=0;i<len;++i){
				if(mask&(1<<i))continue;
				int new_mask=mask|(1<<i);
				for(int j=0;j<k;++j){
					dp[new_mask][(j*base+(digs[i]-'0'))%k]+=dp[mask][j];
				}
			}
		}
		cout<<"Case "<<++cases<<": "<<dp[(1<<len)-1][0]<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}