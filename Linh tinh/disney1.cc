/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=2e2+10;
int a[N][N],dp[N][N];
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)cin>>a[i][j];
    }
    for(int i=1;i<=n;++i)a[i][n+1]=a[i][1],a[n+1][i]=a[1][i];

    memset(dp,0x3f,sizeof(dp));
    dp[1][1]=0;
    for(int i=1;i<=n+1;++i){
        for(int j=1;j<=n+1;++j){
            int nxt=max(i,j)+1;
            dp[i][nxt]=min(dp[i][nxt],dp[i][j]+a[j][nxt]);
            dp[nxt][j]=min(dp[nxt][j],dp[i][j]+a[i][nxt]);
            dp[nxt][nxt]=min(dp[nxt][nxt],dp[i][j]+a[i][nxt]+a[j][nxt]);
        }
    }
    cout<<dp[n+1][n+1];
}
