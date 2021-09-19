/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int M=3e2+10;
pair<int,int> a[N];
long long bit[M][M];
int b[N];
int n,m,t;

bool cmp(pair<int,int> a,pair<int,int> b){
  if(a.first==b.first)return a.second>b.second;
  return a.first<b.first;
}

void upd(int t,int i,int v){
  for(;i<=N;i+=i&(-i))bit[t][i]+=v;
}

long long get(int t,int i){
  long long kq=0;
  for(;i>0;i-=i&(-i))kq+=bit[t][i];
  return kq;
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
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n*m;++i)cin>>a[i].first,a[i].second=i;
    sort(a+1,a+n*m+1,cmp);
    //for(int i=1;i<=n*m;++i)cout<<a[i].first<<' '<<a[i].second<<endl;
    for(int i=1;i<=n*m;++i){
      b[a[i].second]=i;
    }
//    for(int i=1;i<=n*m;++i)cout<<b[i]<<' ';
//    cout<<endl;

    long long ans=0;
    int idx=0;
    for(int i=1;i<=n*m;++i){
      if(i>idx*m)++idx;
      ans+=get(idx,b[i]);
      upd(idx,b[i],1);
    }
    cout<<ans<<endl;
  }
}
