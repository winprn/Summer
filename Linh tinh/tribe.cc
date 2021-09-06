/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=55;
pair<string,int> s[N];
int dp[N][N][N],trace[N][N][N],cnt[5][N];
int n,a,b,c,t,u,v;

void print(int i,int j,int k){
    int p=trace[i][j][k];
    if(p==-1)exit(0);
    cout<<s[p].first;
    if(i<t+1)cout<<' ';
    if(i>1)print(i-1,j-cnt[0][p],k-cnt[1][p]);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>a>>b>>c;
    for(int i=0;i<n;++i)cin>>s[i].first>>s[i].second;
    sort(s,s+n);
    for(int i=0;i<n;++i){
        for(char j:s[i].first)cnt[j-'a'][i]++;
    }

    memset(trace,-1,sizeof(trace));
    for(int cc=1;cc<=c+1;++cc){
        for(int i=0;i<n;++i){
            for(int aa=0;aa<=a;++aa){
                for(int bb=0;bb<=b;++bb){
                    if(aa>=cnt[0][i]&&bb>=cnt[1][i]){
                        if(dp[cc][aa][bb]<dp[cc-1][aa-cnt[0][i]][bb-cnt[1][i]]+s[i].second){
                            dp[cc][aa][bb]=dp[cc-1][aa-cnt[0][i]][bb-cnt[1][i]]+s[i].second;
                            trace[cc][aa][bb]=i;
                        }
                    }
                }
            }
        }
    }
    //cout<<dp[c+1][a][b];

    t=u=v=0;
    for(int cc=c+1;cc>=1;--cc){
        for(int aa=0;aa<=a;++aa){
            for(int bb=0;bb<=b;++bb){
                if(dp[cc][aa][bb]>dp[t][u][v]){
                    t=cc,u=aa,v=bb;
                }
            }
        }
    }
    if(t)print(t,u,v);
}
