/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=3e2+10;
pair<int,int> a[N];
int b[N];
bool mark[N];
int n,m,t;

bool cmp(pair<int,int> a,pair<int,int> b){
  if(a.first==b.first)return a.second>b.second;
  return a.first<b.first;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>t;
  while(t--){
    cin>>n>>m;
    for(int i=1;i<=m;++i)cin>>a[i].first,a[i].second=i,mark[i]=0;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;++i){
      int idx=-1;
      for(int j=1;j<=m;++j)if(a[j].second==i){idx=j;break;}
      b[i]=idx;
    }

    int ans=0;
    for(int i=1;i<=m;++i){
      mark[b[i]]=1;
      for(int j=1;j<b[i];++j)ans+=mark[j];
    }
    cout<<ans<<endl;
  }
}
