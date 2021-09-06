#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e3+10;
int a[2*N],adj[2*N];
bool mark[2*N];
int n,m,t;

signed main(){
	cin>>n>>m;
	for(int i=1;i<=2*n;++i)cin>>a[i];
	for(int i=0;i<m;++i){
		int u,v; cin>>u>>v;
		adj[u]=v,adj[v]=u;
	}
	
	cin>>t;
	if(t==1){
		for(int i=0;i<n;++i){
			int x,pos=-1;
			for(int j=1;j<=2*n;++j){
				if(adj[j]&&!mark[j]&&(pos==-1||a[j]>a[pos]))pos=j;
			}
			
			if(pos==-1){
				for(int j=1;j<=2*n;++j){
					if(!mark[j]&&(pos==-1||a[j]>a[pos]))pos=j;
				}
			}
			
			mark[pos]=1;
			cout<<pos<<endl<<flush;
			cin>>x;
			mark[x]=1;
		}
	}else{
		for(int i=0;i<n;++i){
			int x,pos=-1; cin>>x;
			mark[x]=1;
			if(adj[x]&&mark[adj[x]]==0)pos=adj[x];
			else{
				for(int j=1;j<=2*n;++j){
					if(adj[j]&&!mark[j]&&(pos==-1||a[j]>a[pos]))pos=j;
				}
				
				if(pos==-1){
				for(int j=1;j<=2*n;++j){
					if(!mark[j]&&(pos==-1||a[j]>a[pos]))pos=j;
					}
				}
			}
			
			mark[pos]=1;
			cout<<pos<<endl<<flush;
		}
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}