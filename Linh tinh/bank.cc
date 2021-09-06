/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
pair<int,int> a[N];
bool mark[N];
int n,t;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)return a.second<b.second;

    return a.first>b.first;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("ans", "w", stdout);

    cin>>n>>t;
    for(int i=0;i<n;++i)cin>>a[i].first>>a[i].second;
    sort(a,a+n,cmp);

    long long ans=0;
    int cur=0;
    for(int i=0;i<n;++i){
        for(int j=t-1;j>=0;--j){
            if(!mark[j]&&j<=a[i].second){
                mark[j]=1;
                ans+=a[i].first;
                break;
            }
        }
    }
    cout<<ans;
}
