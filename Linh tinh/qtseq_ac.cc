/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
long long a[N],p[N],s[N];
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("ans", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],p[i]=p[i-1]+a[i];
    for(int i=n;i>=1;--i)s[i]=(i==n?0:s[i+1])+a[i];

    long long mx=0,cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(abs(p[i]-s[j])>mx){
                mx=abs(p[i]-s[j]);
                cnt=1;
            }else if(abs(p[i]-s[j])==mx)++cnt;
        }
    }
    cout<<mx<<' '<<cnt;
}
