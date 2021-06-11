#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef complex<ld> cp;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<cp> vcp;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( int i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( int i = (r) ; i >= (l) ; i-- )
#define log2i(x) (32 - __builtin_clz((x)) - 1)
#define log2ll(x) (64 - __builtin_clzll((x)) - 1)
#define Pi 3.141592653589793
#define sz(x) (int)x.size()
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int N = 207;
const int M = 507;
int n,t;
int a[N],prime[2*M],par[N];
bool kt[2*M],vis[N];
vi edge[N];

bool dfs(int u) {
    if(vis[u]) return 0;
    vis[u]=true;
    for(auto v:edge[u]) {
        if(par[v]==-1||dfs(par[v])) {
            par[v]=u; return 1;
        }
    }
    return 0;
}

int main() {
    fastIO;
    freopen("i","r",stdin);
    freopen("ans","w",stdout);

    cin >> n >> t;
    forw(i,0,n) cin >> a[i];
    if(t==1) {
        int cnt=0;
        forw(i,0,n) cnt+=(a[i]%2);
        cout << min(cnt,n-cnt);
    } else {
        memset(kt,true,sizeof kt);
        int cnt=0;
        forw(i,2,2*M) {
            if(kt[i]) prime[cnt++]=i;
            for(int j=0;j<cnt&&i*prime[j]<2*M;j++) {
                kt[i*prime[j]]=0;
                if(i%prime[j]==0) break;
            }
        }
        forw(i,0,n) if(a[i]%2==0) {
            forw(j,0,n) if(kt[a[i]+a[j]]) edge[i].pb(j);
        }
        memset(par,-1,sizeof par);
        int ans=0;
        forw(i,0,n) if(a[i]%2==0) {
            memset(vis,false,sizeof vis);
            ans+=dfs(i);
        }
        cout << ans;
    }
    return 0;
}
