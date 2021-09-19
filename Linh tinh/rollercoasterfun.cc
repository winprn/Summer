/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

#define sqr(x) (x)*(x)

const int MX=25e3+10;
const int N=1e2+10;
long long a[N],b[N],t[N],dp[MX];
int n,q;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>b[i]>>t[i];
    }

    dp[0]=0;
    for(int i=1;i<=n;++i){
        if(!b[i]){
            for(int j=t[i];j<MX;++j)dp[j]=max(dp[j],dp[j-t[i]]+a[i]);
        }
        else{
            for(int k=0;k*k*b[i]<a[i];++k){
                for(int j=MX-1;j>=t[i];--j)dp[j]=max(dp[j],dp[j-t[i]]+a[i]-k*k*b[i]);
            }
        }
    }

    cin>>q;
    while(q--){
        int x; cin>>x;
        cout<<dp[x]<<endl;
    }
}
