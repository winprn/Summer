/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=3e5+10;
int x[N];
int a,b,t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    for(int i=0;i<N;++i)x[i]=(i?i^x[i-1]:0);
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(x[a-1]==b)cout<<a<<endl;
        else{
            int need=x[a-1]^b;
            cout<<a+1+(need==a)<<endl;
        }
    }
}
