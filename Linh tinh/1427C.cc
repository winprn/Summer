/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int t[N],x[N],y[N],dp[N];
int n,r;

int dist(int i,int j){
    return (abs(x[i]-x[j])+abs(y[i]-y[j]));
}

bool ok(int i,int j){
    return (dist(i,j)<=abs(t[i]-t[j]));
}

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>r>>n;
    t[0]=0,x[0]=1,y[0]=1;
    for(int i=1;i<=n;++i)cin>>t[i]>>x[i]>>y[i];

    dp[0]=1;
    for(int i=1;i<=n;++i)dp[i]=(ok(0,i)?1:-1);
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=max(1,i-4*r);j<i;++j){
            if(ok(j,i)&&dp[j]!=-1){
                //cout<<j<<' '<<i<<endl;
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
