#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

pair<ll,ll>f[50];
ll n,t,k;

ll dfs(ll n, ll k){
    if(n==0)return min(k,1LL);
    if(n==1)return 0;
    if(k==f[n].se)return f[n].fi;
    if(k<=f[n-2].se)return dfs(n-2,k);

    return f[n-2].fi+dfs(n-1,k-f[n-2].se);
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    f[0]={1,1},f[1]={0,1};
    for(int i=2;i<=45;++i){
        f[i].fi+=f[i-1].fi+f[i-2].fi;
        f[i].se+=f[i-1].se+f[i-2].se;
    }

    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<dfs(n,k)<<endl;
    }
}