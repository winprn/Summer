/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

const int N=6e2+10;
vector<int> all;
int a[N],b[N],c[N],dp[N][N],cost[N][N];
int n;

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.first==b.first.first)return a.first.second<b.first.second;

    return a.first.first<b.first.first;
}

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>n;
    for(int i=0;i<n;++i){
        int l,r,w; cin>>l>>r>>w;
        a[i]=l,b[i]=r,c[i]=w;
        all.push_back(l);
        all.push_back(r);
    }
    all.push_back(-1),all.push_back(10005);
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());

    for(int d=1;d<all.size();++d){
        for(int i=0;i+d<all.size();++i){
            int j=i+d,idx=-1;
            for(int k=0;k<n;++k){
                if((a[k]>all[i])&&(b[k]<all[j])&&(idx==-1||c[k]>c[idx]))idx=k;
            }
            if(idx==-1)continue;
            else{
                dp[i][j]=1e9;
                int l=0,r=0;
                while(all[l]!=a[idx])++l;
                while(all[r]!=b[idx])++r;
                for(int k=l;k<=r;++k)dp[i][j]=min(dp[i][j],c[idx]+dp[i][k]+dp[k][j]);
            }
        }
    }
    cout<<dp[0][all.size()-1];
}
