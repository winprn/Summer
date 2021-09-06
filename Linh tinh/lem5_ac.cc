/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N=1e5+10;
pair<int,int> a[N];
int dp[N];
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("ans","w",stdout);

    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i].fi,a[i].se=i;
    sort(a,a+n);

    int ans=0;
    for(int i=1;i<=100;++i){
        int k=0;
        for(int j=0;j<n;++j)dp[j]=1;
        for(int j=1;j<n;++j){
            pair<int,int> cur=make_pair(a[j].fi-i,a[j].se);
            while(k+1<n&&a[k+1]<=cur)++k;
            if(a[k].fi==cur.fi&&a[k].se<cur.se)dp[j]=max(dp[j],dp[k]+1);
            else dp[j]=1;
            ans=max(ans,dp[j]);
            if(dp[j]==3)cout<<i<<' '<<a[j].se<<endl;
        }
    }
    cout<<ans;
}
