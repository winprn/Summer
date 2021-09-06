#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;
typedef pair<int,int> pii;

const int N=17;
pii a[N];
int dp[(1<<N)],num[N][N];
int n,t,cases=0;

pii operator-(const pii& a,const pii& b){
	return{a.fi-b.fi,a.se-b.se};
}

bool ok(pii i,pii j,pii k){
	if(i==k||j==k)return 1;
	i=i-k,j=j-k;
	
	return(1LL*i.fi*j.se==1LL*i.se*j.fi&&1LL*i.fi*j.fi+1LL*i.se*j.se<0);
}

signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i].fi>>a[i].se;
		sort(a,a+n);
		
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				num[i][j]=0;
				for(int k=0;k<n;++k){
					//if(k==j)continue;
					if(ok(a[i],a[j],a[k]))num[i][j]|=(1<<k);
				}
			}
		}
		
		memset(dp,0x3f,sizeof dp);
		dp[0]=0;
		for(int mask=0;mask<(1<<n)-1;++mask){
			int rev_mask=((1<<n)-1)^mask;
			int best=__builtin_ctz(rev_mask);
			while(rev_mask){
				int cur=__builtin_ctz(rev_mask);
				rev_mask=rev_mask^(1<<cur);
				
				dp[mask|num[best][cur]]=min(dp[mask|num[best][cur]],1+dp[mask]);
			}
		}
		//for(int i=0;i<(1<<n);++i)cout<<dp[i]<<endl;
		cout<<"Case "<<++cases<<": "<<dp[(1<<n)-1]<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}