/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=2e2+10;
int dp[N][N];
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i){
        int x; cin>>x;
        dp[i+n][i+n]=dp[i][i]=x&1;
    }

    for(int i=2;i<=n;++i){
        for(int j=0;j<2*n;++j){
            int k=i+j-1;
            if(k>=2*n)break;
            dp[j][k]=max(dp[j][j]-dp[j+1][k],dp[k][k]-dp[j][k-1]);
        }
    }

    int ans=0;
    for(int i=0;i<n;++i)ans+=(dp[i][i]-dp[i+1][i+n-1]>0);
    cout<<ans;
}
