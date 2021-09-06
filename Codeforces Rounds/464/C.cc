/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],p[N];
int n,s,t,mx=-1;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    cin>>s>>t,--s,--t;
    for(int i=0;i<n;++i){
        int ss=(s-i),tt=(t-i);
        ss=(ss%n+n)%n,tt=(tt%n+n)%n;
        p[ss]+=a[i],p[tt]-=a[i];
        if(ss>=tt)p[0]+=a[i];
    }

    int cur=0,idx=-1;
    for(int i=0;i<n;++i){
        cur+=p[i];
        if(cur>mx)mx=cur,idx=i;
    }
    cout<<idx+1;
}
