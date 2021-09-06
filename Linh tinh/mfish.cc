/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
pair<int,int> b[N];
int a[N],p[N],dp[N];
int n,m;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],p[i]=p[i-1]+a[i];
    cin>>m;
    for(int i=1;i<=m;++i)cin>>b[i].first>>b[i].second;
    sort(b+1,b+m+1);

    int idx=0;
    for(int i=1;i<=n;++i){
        while(idx<m&&b[idx+1].first<=i)++idx;
        dp[i]=dp[i-1];
        if(idx){
            if(b[idx].first+b[idx].second-1>=i&&i-b[idx].second>=b[idx-1].first){
                dp[i]=max(dp[i],dp[i-b[idx].second]+p[i]-p[i-b[idx].second]);
            }
        }
    }
    cout<<dp[n];
}
