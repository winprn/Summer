#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=2e5+10;
ll a[N],p[N],s[N];
ll ans=0;
int n,k,x;

signed main(){
	cin>>n>>k>>x;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i){
		p[i]=(i?p[i-1]|a[i]:a[i]);
	}
	for(int i=n-1;i>=0;--i){
		s[i]=((i==n-1)?a[i]:s[i+1]|a[i]);
	}
	
	ll mx=1;
	while(k--)mx*=1LL*x;
	for(int i=0;i<n;++i){
		ll tmp=a[i]*mx;
		ans=max(ans,(i?p[i-1]:0)|tmp|(i==n-1?0:s[i+1]));
	}
	cout<<ans;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}