/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int MX=3e4+10;
const int N=1e2+10;
int a[N],dp[MX];
int n,m;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];

    memset(dp,-1,sizeof(dp));
    dp[0]=-2;
    for(int i=0;i<n;++i){
      for(int j=0;j<MX;++j){
        if(j+a[i]>=MX)break;
        if(dp[j]!=-1){
          if(dp[j]==n||dp[j+a[i]]!=-1)dp[j+a[i]]=n;
          else dp[j+a[i]]=i;
        }
      }
    }

    cin>>m;
    while(m--){
      int x; cin>>x;
      if(dp[x]==-1)cout<<"Impossible"<<'\n';
      else if(dp[x]==n)cout<<"Ambiguous"<<'\n';
      else{
        vector<int> ans;
        int cur=dp[x];
        //cout<<cur<<endl;
        while(cur!=-2){
          ans.push_back(cur);
          x-=a[cur];
          cur=dp[x];
        }
        sort(ans.begin(),ans.end());

        for(int i=0;i<ans.size();++i)cout<<ans[i]+1<<(i==ans.size()-1)[" \n"];
      }
    }
}
