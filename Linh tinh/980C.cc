#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e5+10;
int a[N],val[300];
int n,m;

signed main(){
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	
	memset(val,-1,sizeof val);
	for(int i=0;i<n;++i){
		if(val[a[i]]==-1){
			bool ok=0;
			for(int ii=a[i]-1;ii>=max(0,a[i]-m+1);--ii){
				//if(a[i]-j<0)continue;
				if(val[ii]!=-1&&(!ii||val[ii]!=val[ii-1])){
					for(int j=ii+1;j<=a[i];++j)val[j]=val[ii];
					
					ok=1;
					break;
				}
			}
			
			if(!ok){
				for(int ii=max(0,a[i]-m+1);ii<=a[i];++ii){
					if(val[ii]==-1){
						for(int j=ii;j<=a[i];++j)val[j]=ii;
						break;
					}
				}
			}
		}
	}
	
	for(int i=0;i<n;++i)cout<<val[a[i]]<<' ';	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}