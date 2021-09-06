/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
long long p[N],a[2][N],cnt[2][N];
long long mx=-1e16,ans=0;
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    cnt[0][0]=cnt[1][0]=1;
    for(int i=0;i<n;++i){
        cin>>p[i];
        if(!i){
            a[0][i]=a[1][i]=p[i];
        }else{
            p[i]+=p[i-1];
            a[0][i]=max(a[0][i-1],p[i]);
            a[1][i]=min(a[1][i-1],p[i]);
            if(p[i]>a[0][i-1])cnt[0][i]=1;
            else if(p[i]==a[0][i-1])cnt[0][i]=cnt[0][i-1]+1;
            else cnt[0][i]=cnt[0][i-1];

            if(p[i]<a[1][i-1])cnt[1][i]=1;
            else if(p[i]==a[1][i-1])cnt[1][i]=cnt[1][i-1]+1;
            else cnt[1][i]=cnt[1][i-1];
        }
    }
    //for(int i=1;i<=n;++i)cout<<p[i]<<' '<<a[0][i]<<' '<<cnt[0][i]<<' '<<a[1][i]<<' '<<cnt[1][i]<<endl;

    for(int i=n-1;i>=1;--i){
        if(abs(a[1][i-1]-p[n-1]+p[i-1])>mx){
            mx=abs(a[1][i-1]-p[n-1]+p[i-1]);
            ans=cnt[1][i-1];
        }else if(abs(a[1][i-1]-p[n-1]+p[i-1])==mx)ans+=cnt[1][i-1];
        if(a[0][i-1]==a[1][i-1])continue;

        if(abs(a[0][i-1]-p[n-1]+p[i-1])>mx){
            mx=abs(a[0][i-1]-p[n-1]+p[i-1]);
            ans=cnt[0][i-1];
        }else if(abs(a[0][i-1]-p[n-1]+p[i-1])==mx)ans+=cnt[0][i-1];
    }
    cout<<mx<<' '<<ans;
}
