/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

const int N=5e2+10;
string s;
vector<char> a;
int dp[N][N];
int n;

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>n>>s;
    {
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n&&s[j]==s[i])++j;
            a.push_back(s[i]);
            i=j;
        }
    }
    //for(char i:a)cout<<i<<' ';

    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<a.size();++i)dp[i][i]=1;
    for(int len=1;len<a.size();++len){
        for(int i=0;i+len<a.size();++i){
            int j=i+len;
            for(int k=i;k<j;++k)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]-(a[i]==a[j]));
        }
    }
    cout<<dp[0][a.size()-1];
}
