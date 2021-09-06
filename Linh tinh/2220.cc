#include <bits/stdc++.h> 
using namespace std; 
#define pb push_back
 
typedef long long ll;

vector<int> digits;
ll dp[20][15][3][3];
ll l,r;

ll _dp(int cur,int lst,bool smaller,bool isNum){
	if(cur==(int)digits.size())return 1;
	ll &ans=dp[cur][lst][smaller][isNum];
	if(ans!=-1)return ans;
	
	int lim=digits[cur];
	if(smaller)lim=9;
	
	ans=0;
	for(int i=0;i<=lim;++i){
		if(i==lst){
			if(isNum)continue;
		}
		//if(lst==0)cout<<i<<endl;
		int tmp=smaller;
		if(smaller==0&&i<lim)tmp=1;
		ans+=_dp(cur+1,i,tmp,(isNum||i!=0));
	}
	return ans;
}

ll solve(ll x){
	digits.clear();
	//if(x%10==0)digits.pb(0);
	while(x){
		digits.pb(x%10);
		x/=10;
	}
	reverse(digits.begin(),digits.end());
	// for(int i:digits)cout<<i<<' ';
	// cout<<endl;
	
	memset(dp,-1,sizeof(dp));
	return _dp(0,10,0,0);
}

signed main(){
	cin>>l>>r;
	cout<<solve(r)-solve(l-1);
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}