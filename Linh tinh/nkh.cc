/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

string s,t,S;
vector<int> ans;

void dfs(int i,int j,int k){
    if(k==(int)S.size()){
        for(int l:ans)cout<<l;
        exit(0);
    }

    if(i<s.size()&&s[i]==S[k])ans.push_back(1),dfs(i+1,j,k+1),ans.pop_back();
    if(j<t.size()&&t[j]==S[k])ans.push_back(2),dfs(i,j+1,k+1),ans.pop_back();;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>s>>t>>S;
    dfs(0,0,0);
}
