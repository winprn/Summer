/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
string s,t;
vector<pair<char,char>> ans;
int par[N];
int n;

int find(int u){
    return(par[u]<0?u:par[u]=find(par[u]));
}

bool join(int u,int v){
    if((u=find(u))==(v=find(v)))return 0;

    return par[u]=v,1;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>s>>t;
    memset(par,-1,sizeof(par));
    for(int i=0;i<n;++i){
        if(s[i]!=t[i]&&find(s[i]-'a')!=find(t[i]-'a')){
            ans.push_back({s[i],t[i]});
            join(s[i]-'a',t[i]-'a');
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i.first<<' '<<i.second<<endl;
}
