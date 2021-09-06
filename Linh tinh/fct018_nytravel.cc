// #include <bits/stdc++.h>
//  
// using namespace std;
//  
// #define pb push_back
// #define fi first
// #define se second
// #define MOD 1000000007
//  
// typedef long long ll;
// 
// const int N=1e5+10;
// int par[N],cnt[N];
// int n,m;
// 
// int find(int u){
	// return(par[u]<0?u:par[u]=find(par[u]));
// }
// 
// bool join(int u,int v){
	// if((u=find(u))==(v=find(v)))return 0;
// 	
	// return par[u]=v,cnt[v]+=cnt[u],1;
// }
// 
// signed main(){
	// cin>>n>>m;
	// for(int i=1;i<=n;++i)par[i]=-1,cnt[i]=1;
	// for(int i=0;i<m;++i){
		// int u,v; cin>>u>>v;
		// if(find(u)!=find(v))join(u,v);
	// }	
// 	
	// int ans=cnt[find(1)],mx=0;
	// for(int i=1;i<=n;++i){
		// if(find(i)==find(1))continue;
		// mx=max(mx,cnt[find(i)]);
	// }
	// cout<<ans+mx;
// 	
// #ifdef LOCAL
    // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
// #endif
// }
#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5;
vector<int> a[N];
int parent[N];
int cur[N];
int find_parent(int u)
{
    if(parent[u]!=u)
    {
        parent[u] = find_parent(parent[u]);
    }
    return parent[u];
}
void join(int u,int v)
{
    int u_1 = find_parent(u);
    int v_1 = find_parent(v);
    if(u_1 == v_1) return;
    if(u_1 != v_1)
    {
        if(cur[u_1] >= cur[v_1])
        {
            parent[v_1] = u_1;
            cur[u_1] += cur[v_1];
        }
        else
        {
            parent[u_1] = v_1;
            cur[v_1] += cur[u_1];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("testLock.inp","r",stdin);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        parent[i] = i;
        cur[i] = 1;
    }
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin >> u >> v;
        if(find_parent(u)!=find_parent(v))join(u,v);
    }
    
    int mx = 0;
    for(int i=1;i<=n;++i)
    {
        if(find_parent(i)!=find_parent(1))
        {
            mx = max(mx,cur[find_parent(i)]);
        }
    }
    cout << cur[find_parent(1)]+mx;
    return 0;
}