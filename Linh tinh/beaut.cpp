#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e5+10;
ll a[N],pr[N],sf[N];
int n;

signed main(){
	// freopen("beaut.inp","r",stdin);
	// freopen("beaut.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i){
		pr[i]=(i?pr[i-1]:0)+a[i];
	}
	for(int i=n-1;i>=0;--i){
		sf[i]=(i==n-1?0:sf[i+1])+a[i];
	}
	
	int ans=-1;
	for(int i=0;i<n;++i){
		if(pr[i]==sf[i+1]){
			ans=i+1;
			break;
		}
	}
	cout<<ans<<endl;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}