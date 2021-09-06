/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

string s;
int n,t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n>>s;
        for(int i=0;i<n;++i){
            if(s[i]=='D')s[i]='U';
            else if(s[i]=='U')s[i]='D';
        }
        cout<<s<<endl;
    }
}
