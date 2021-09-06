/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
const int N=1e3+10;
string S;
vector<pair<string,int>> a,b[N];
int dp[N];
int n;

int _dp(int idx){
    if(idx==S.size())return 1;
    int &ans=dp[idx];
    if(ans!=-1)return ans;
    ans=0;

    for(auto i:b[S[idx]]){
        if(i.first.size()+idx>S.size())continue;

        bool ok=1;
        for(int j=0;j<i.first.size();++j){
            if(i.first[j]!=S[idx+j]){
                ok=0;
                break;
            }
        }
        if(!ok)continue;

        long long tmp=(1LL*_dp(idx+i.first.size())*i.second)%MOD;
        ans=(ans+tmp)%MOD;
    }

    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>S;
    for(int i=0;i<n;++i){
        string s; cin>>s;
        int val; cin>>val;
        a.push_back({s,val});
    }
    sort(a.begin(),a.end());

    for(auto i:a){
        b[i.first[0]].push_back(i);
    }

    dp[0]=1;
    for(int i=0;i<S.size();++i){
        for(auto j:b[S[i]]){
            if(j.first.size()+i>S.size())continue;

            bool ok=1;
            for(int k=0;k<j.first.size();++k){
                if(j.first[k]!=S[i+k]){
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;

            int tmp=(1LL*dp[i]*j.second)%MOD;
            dp[i+j.first.size()]=(dp[i+j.first.size()]+tmp)%MOD;
        }
    }

    cout<<dp[S.size()]<<endl;
//    memset(dp,-1,sizeof(dp));
//    cout<<_dp(0);
}
