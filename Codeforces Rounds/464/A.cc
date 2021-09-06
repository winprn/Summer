/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=5e3+10;
int a[N];
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];

    bool ok=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(a[i]==j&&a[a[j]]==i){ok=1;break;}
        }
        if(ok)break;
    }
    cout<<(ok?"YES":"NO");
}
