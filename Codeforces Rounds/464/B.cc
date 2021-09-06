/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
long long a[N];
long long n,k;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>k>>n;
    pair<int,long long> ans;
    long long mx=-1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        long long cnt=k/a[i];

        if(a[i]*cnt>mx)mx=a[i]*cnt,ans={i,cnt};
    }
    cout<<ans.first<<' '<<ans.second;
}
