/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=3e5+10;
const int M=15;
int a[N][M];
pair<int,int> ans;
int n,m;

bool ok(int x){
  vector<int> mask(1<<m,-1);
  for(int i=0;i<n;++i){
    int tmp=0;
    for(int j=0;j<m;++j){
      if(a[i][j]>=x)tmp^=(1<<j);
    }
    mask[tmp]=i;
  }
  if(mask[(1<<m)-1]!=-1)return ans={mask[(1<<m)-1],mask[(1<<m)-1]},1;

  for(int i=0;i<(1<<m);++i){
    for(int j=0;j<(1<<m);++j){
      if(mask[i]!=-1&&mask[j]!=-1&&(i|j)==(1<<m)-1){
        ans={mask[i],mask[j]};
        return 1;
      }
    }
  }
  return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>n>>m;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j)cin>>a[i][j];
  }

  int l=0,r=1e9;
  for(int i=0;i<32;++i){
    int m=l+(r-l)/2;
    if(ok(m))l=m+1;
    else r=m-1;
  }
  cout<<ans.first+1<<' '<<ans.second+1;
}
