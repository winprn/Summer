/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],b[N],tmp[2*N],pos[2*N];
int n,t;

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=2*n+2;++i)tmp[i]=1e9;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i)cin>>b[i];

        int ans=1e9;
        for(int i=1;i<=n;++i)pos[a[i]]=i-1;
        for(int i=1;i<=n;++i)pos[b[i]]=i-1;
        for(int i=2*n;i>0;i-=2)tmp[i]=min(tmp[i+2],pos[i]);
        for(int i=1;i<2*n;i+=2)ans=min(ans,pos[i]+tmp[i+1]);
        cout<<ans<<endl;
    }
}
