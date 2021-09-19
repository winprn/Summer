/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

string s;
int n,t;

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>t;
    while(t--){
        cin>>n>>s;
        int ans=0;
        for(int i=0;i<n;++i){
            ans+=(s[i]-'0');
            ans+=(i!=n-1&&s[i]!='0');
        }
        cout<<ans<<endl;
    }
}
