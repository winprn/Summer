/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
string s;
int dp[30][N];
int n,q;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>q>>s;
    s=" "+s;
    for(int i=1;i<=n;++i){
        for(int j=0;j<26;++j)dp[j][i]=dp[j][i-1];
        dp[s[i]-'a'][i]++;
    }

    while(q--){
        int l,r; cin>>l>>r;
        char c; cin>>c;
        cout<<dp[c-'a'][r]-dp[c-'a'][l-1]<<'\n';
    }
}
