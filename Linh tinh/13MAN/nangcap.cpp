#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int N=1e3+10;
vector<pair<int,pair<int,int>>> edges;
int c[N],w[N],par[N];
ll l=1e9,r=-1;
int n,m;

int find(int u){
    return (par[u]==-1?u:par[u]=find(par[u]));
}

bool join(int u,int v){
    if ((u=find(u))==(v=find(v)))return 0;

    return par[u]=v,1;
}

ll get(ll x){
    memset(par,-1,sizeof par);
    auto nEdges=edges;
    ll kq=0;
    for(int i=0;i<m;++i){
        nEdges[i].fi=1000*c[i]-x*w[i];
    }
    sort(nEdges.begin(),nEdges.end());

    for(auto i:nEdges){
        int u=i.se.fi,v=i.se.se;
        ll w=i.fi;
        if(find(u)!=find(v)){
            join(u,v);
            kq+=w;
        }
    }

    return kq;
}

int main() {
    cout.precision(3);
    cout<<fixed;
    freopen("nangcap.inp", "r", stdin);
    freopen("nangcap.out", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v>>c[i]>>w[i];
        edges.pb({0,{u,v}});
        l=min(l,1LL*1000*c[i]/w[i]),r=max(r,1LL*1000*(c[i]/w[i]+1));
    }

    ll ans=0;
    for(int i=0;i<32;++i){
        ll m=l+(r-l)/2;
        if(get(m)<=0){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    cout<<ans/1000.<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}