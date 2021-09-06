#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=20;
vector<int> digs;
ll dp[N][2][2];
int n,t;

ll _dp(int pos,int smaller,int lst){
	if(pos==(int)digs.size())return 0;
	ll &ans=dp[pos][smaller][lst];
	if(ans!=-1)return ans;
	
	if(smaller){
		int tmp=smaller;
		if(1>digs[pos])tmp=0;
		
		ans=_dp(pos+1,digs[pos],0);
		if(lst)ans+=1+_dp(pos+1,tmp,1);
	}else{
		int tmp=digs[pos];
		ans=_dp(pos+1,tmp,0);
	}
	return ans;
}

signed main(){
	memset(dp,-1,sizeof dp);
	cin>>t;
	while(t--){
		cin>>n;
		digs.clear();
		while(n){
			digs.pb(n%2);
			n/=2;
		}
		for(int i:digs)cout<<i<<' ';
		reverse(digs.begin(),digs.end());
		
		cout<<_dp(0,digs[0],0)<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}