/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=2e2+10;
int a[N][2],dp[N][2][N][2];
int n,m,sum=0,mn=1e9;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    while(cin>>n>>m,n){
        for(int i=0;i<n;++i)for(int j=0;j<2;++j)cin>>a[i][j],sum+=a[i][j];
        for(int i=0;i<n;++i){
            for(int j=0;j<2;++j){
                for(int k=0;k<=m;++k){
                    for(int l=0;l<2;++l)dp[i][j][k][l]=1e9;
                }
            }
        }

        dp[0][0][0][0]=0,dp[0][1][0][0]=0;
        dp[0][0][1][1]=a[0][0],dp[0][1][1][1]=a[0][1];
        for(int i=1;i<n;++i){
            for(int k=0;k<=m;++k){
                dp[i][0][k][0]=min({dp[i-1][0][k][0],dp[i-1][0][k][1],dp[i-1][1][k][0],dp[i-1][1][k][1]});
                dp[i][1][k][0]=min({dp[i-1][0][k][0],dp[i-1][0][k][1],dp[i-1][1][k][0],dp[i-1][1][k][1]});
                dp[i][0][k+1][1]=min({dp[i-1][0][k][0],dp[i-1][0][k][1],dp[i-1][1][k][0]})+a[i][0];
                dp[i][1][k+1][1]=min({dp[i-1][0][k][0],dp[i-1][1][k][1],dp[i-1][1][k][0]})+a[i][1];
            }
        }

        mn=min({dp[n-1][0][m][0],dp[n-1][0][m][1],dp[n-1][1][m][0],dp[n-1][1][m][1]});
        cout<<sum-mn<<endl;
    }
}
