#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=7e3+10;
ll a[N],b[N];
bool mark[N];
int n;

signed main(){
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];
	
	for(int i=0;i<n;++i){
		bool ok=0;
		for(int j=0;j<n;++j){
			if(i==j)continue;
			if(a[i]==a[j]){
				ok=1;
				break;
			}
		}
		mark[i]=ok;
	}
	
	ll ans=0;
	for(int i=0;i<n;++i){
		bool ok=0;
		for(int j=0;j<n;++j){
			if(mark[j]&&(a[i]&a[j])==a[i]){
				ok=1;
				break;
			}
		}
		
		if(ok)ans+=b[i];
	}
	cout<<ans;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}