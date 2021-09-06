/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int a[N];
int n,k;

bool ok(int x){
    int kq=0;
    for(int i=0;i<n;++i){
        kq+=(a[i]+x-1)/x;
    }

    return kq<=k;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    while(cin>>n>>k,n!=-1){
        for(int i=0;i<n;++i)cin>>a[i];

        int l=1,r=1e8,ans=0;
        for(int i=0;i<32;++i){
            int m=(l+r)/2;
            if(ok(m))ans=m,r=m-1;
            else l=m+1;
        }
        cout<<ans<<endl;
    }
}
