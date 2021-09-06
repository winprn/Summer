#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=2e3+10;
int f[N][N];
int n,m,t;

signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)f[i][j]=-1e9;
		
		f[0][0]=0;
		for(int i=1;i<=n;++i){
			int x; cin>>x;
			for(int j=0;j<=i;++j){
				f[i][j]=max(f[i-1][j-1],f[i-1][j]+(x==i-j));
			}
		}
		
		int res=-1;
		for(int i=0;i<=n;++i)if(f[n][i]>=m){res=i;break;}
		cout<<res<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}