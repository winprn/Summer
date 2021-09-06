#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

ll n,m,t;

signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		ll ans=1;
		for(int i=1;i<=30;++i){
			ll mn=(1<<(i-1));
			ll mx=min(n,(1LL<<i)-1);
			if(mn<=mx)ans=ans*(mx-mn+2)%m;
		}
		cout<<(ans-1+m)%m<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}