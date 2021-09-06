/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
long long a[N],p[N];
int n,m,k;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)p[i]=p[i-1]+a[i];

    for(int i=n;i>=n-m+1;--i){
        if(a[i]-a[i-m+1]<=k){
            cout<<p[i]-p[i-m];
            return 0;
        }
    }
    cout<<"-2";
}
