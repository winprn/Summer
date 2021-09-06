/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

bool ok(int x){

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        zip();

        for(int i=1;i<=n;++i)upd(1,1,n,i,a[i]),idx[a[i]].pb(i);
        for(int i=1;i<=n;++i){
            int l=1,r=lower_bound(idx[a[i]].begin(),idx[a[i]].end(),i)-idx[a[i]].begin();
            for(int j=0;j<32;++j){
                int m=(l+r)/2;
                if(ok(m))ans=m,r=m-1;
                else l=m+1;
            }
            res[i]=(i-ans);

            l=upper_bound(idx[a[i]].begin(),idx[a[i]].end(),i)-idx[a[i]].begin(),r=idx[a[i]].end();
            for(int j=0;j<32;++j){
                int m=(l+r)/2;
                if(ok(m))ans=m,l=m+1;
                else r=m-1;
            }
            res[i]+=(ans-i+1);
        }

        for(int i=1;i<=n;++i)cout<<res[i]<<' ';
    }
}
