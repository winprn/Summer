/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
long long a[N],dp[N][5];
long long n,d;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>d;
    for(int i=0;i<n;++i){
        cin>>a[i];
        for(int j=0;j<3;++j)dp[i][j]=1;
    }

    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(a[i]-d>=a[j]-d){
                dp[i][0]=max(dp[i][0],dp[j][0]+1);
            }
            if(a[i]-d>=a[j]){
                dp[i][0]=max(dp[i][0],dp[j][1]+1);
            }
            if(a[i]-d>=a[j]+d){
                dp[i][0]=max(dp[i][0],dp[j][2]+1);
            }
            if(a[i]>=a[j]-d){
                dp[i][1]=max(dp[i][1],dp[j][0]+1);
            }
            if(a[i]>=a[j]){
                dp[i][1]=max(dp[i][1],dp[j][1]+1);
            }
            if(a[i]>=a[j]+d){
                dp[i][1]=max(dp[i][1],dp[j][2]+1);
            }
            if(a[i]+d>=a[j]-d){
                dp[i][2]=max(dp[i][2],dp[j][0]+1);
            }
            if(a[i]+d>=a[j]){
                dp[i][2]=max(dp[i][2],dp[j][1]+1);
            }
            if(a[i]+d>=a[j]+d){
                dp[i][2]=max(dp[i][2],dp[j][2]+1);
            }
        }
    }

    long long ans=0;
    for(int i=0;i<n;++i)for(int j=0;j<3;++j)ans=max(ans,dp[i][j]);
    cout<<ans;
}
