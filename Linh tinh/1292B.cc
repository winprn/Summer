#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define sqr(x) (x)*(x)
#define MOD 1000000007
 
typedef long long ll;

const ll MX=(1LL<<62)-1;
ll x0,y0,ax,ay,bx,by,sx,sy,t;

long double d(ll x,ll y){
	return sqrt(sqr(sx-x)+sqr(sy-y));
}

signed main(){
	cin>>x0>>y0>>ax>>ay>>bx>>by;
	cin>>sx>>sy>>t;
	
	vector<pair<ll,ll>> cords;
	ll curx=x0,cury=y0;
	while((MX-bx)/ax>=curx&&(MX-by)/ay>=cury){
		cords.pb({curx,cury});
		
		//cout<<curx<<' '<<cury<<endl;
		curx=ax*curx+bx,cury=ay*cury+by;
	}
	
	int n=(int)cords.size(),ans=0;
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j){
			ll len=cords[j].fi-cords[i].fi+cords[j].se-cords[i].se;
			ll tmp=abs(sx-cords[i].fi)+abs(sy-cords[i].se);
			ll tmp2=abs(sx-cords[j].fi)+abs(sy-cords[j].se);
			
			if(len<=t-tmp||len<=t-tmp2)ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}