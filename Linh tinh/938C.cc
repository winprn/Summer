#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define sqr(x) (x)*(x)
#define MOD 1000000007
 
typedef long long ll;

int x,ans,ans2;
int t;

ll get(int x){
	int kq=sqrt(x);
	for(int i=-2;i<=2;++i){
		if(kq+i>=0&&sqr(kq+i)==x)return kq;
	}
	
	return -1;
}

signed main(){
	cin>>t;
	while(t--){
		cin>>x;
		ans=ans2=-1;
		for(int i=1;i==1||sqr(i)-sqr(i/2)<=x;++i){
			int cur=sqr(i)-x;
			if(cur<0)continue;
			int tmp=get(cur);
			if(tmp<=0)continue;
			
			int m=i/tmp;
			if(m>0&&sqr(i)-sqr(i/m)==x){
				ans=i,ans2=m;
				break;
			}
		}
		
		if(ans==-1)cout<<ans;
		else cout<<ans<<' '<<ans2;
		cout<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}