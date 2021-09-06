#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;
typedef pair<int,int> pii;

const int td[8]={-1,-1,-1,0,0,1,1,1};
const int tc[8]={-1,0,1,-1,1,-1,0,1};
const int N=55;
char a[N][N];
int h[N][N],val[N*N];
bool vis[N][N];
pii s;
int n,m;

bool check(int i,int j){
	return(i>=0&&i<n&&j>=0&&j<n);
}

void dfs(pii u,int l,int r){
	if(vis[u.fi][u.se])return ;
	vis[u.fi][u.se]=1;
	
	for(int i=0;i<8;++i){
		pii v={u.fi+td[i],u.se+tc[i]};
		if(h[v.fi][v.se]<l||h[v.fi][v.se]>r)continue;
		dfs(v,l,r);
	}
}

bool ok(int l,int r){
	memset(vis,0,sizeof(vis));
	
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(i==s.fi&&j==s.se){
				if(h[i][j]<l||h[i][j]>r)return 0;
			}
		}
	}
	
	dfs(s,l,r);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(a[i][j]=='N'&&!vis[i][j])return 0;
		}
	}
	return 1;
}

signed main(){
	// freopen("mail.inp","r",stdin);
	// freopen("mail.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
			if(a[i][j]=='B')s.fi=i,s.se=j;
		}
	}	
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>h[i][j],val[m++]=h[i][j];
	sort(val,val+m);
	m=unique(val,val+m)-val;
	
	int ans=1e9;
	for(int i=0;i<m;++i){
		int l=i,r=m-1;
		for(int j=0;j<32;++j){
			int m=(l+r)/2;
			if(ok(val[i],val[m]))r=m;
			else l=m+1;
		}
		
		if(ok(val[i],val[l]))ans=min(ans,val[l]-val[i]);
	}
	cout<<ans<<endl;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}