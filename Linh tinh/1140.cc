#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=2e5+10;
vector<pair<int,int>> project[2*N];
ll p[N],dp[N];
int l[N],r[N];
int n;

signed main(){
	cin>>n;
	map<int,int> m;
	for(int i=0;i<n;++i)cin>>l[i]>>r[i]>>p[i],++r[i],m[l[i]],m[r[i]];
	
	int total=0;
	for(auto& i:m)i.se=total++;
	for(int i=0;i<n;++i){
		project[m[r[i]]].emplace_back(m[l[i]],p[i]);
	}
	
	for(int i=0;i<total;++i){
		if(i)dp[i]=dp[i-1];
		for(auto j:project[i])dp[i]=max(dp[i],dp[j.fi]+j.se);
	}
	cout<<dp[total-1];
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}