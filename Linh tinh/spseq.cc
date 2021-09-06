/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],b[N],dp[2][N];
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];

    int lis=0,lds=0;
    for(int i=1;i<=n;++i){
        int j=lower_bound(b+1,b+lis+1,a[i])-b;
        b[j]=a[i], lis=max(lis,j);
        dp[0][i]=lis;
    }

    memset(b,0,sizeof(b));
    for(int i=n;i>=1;--i){
        int j=lower_bound(b+1,b+lds+1,a[i])-b;
        b[j]=a[i], lds=max(lds,j);
        dp[1][i]=lds;
    }

//    for(int i=1;i<=n;++i)cout<<dp[0][i]<<' ';
//    cout<<endl;
//    for(int i=1;i<=n;++i)cout<<dp[1][i]<<' ';
//    cout<<endl;

    int ans=0;
    for(int i=1;i<=n;++i){
        if((2*min(dp[0][i],dp[1][i])-1)&1)ans=max(ans,2*min(dp[0][i],dp[1][i])-1);
    }
    cout<<ans;
}
