/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
double x[N],y[N];
int n,t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout.fixed;
//    freopen("i", "r", stdin);
//    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n;
        double X=0,Y=0,ans=0;
        for(int i=0;i<n;++i){
            cin>>x[i]>>y[i];
            ans=max(ans,x[i]+y[i]);
        }

        cout<<ans<<endl;
    }
}
