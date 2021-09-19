/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int td[4]={0,0,1,-1};
const int tc[4]={1,-1,0,0};
const int N=5e2+10;
bool vis[3][N][N];
int n,m,si,sj,fi,fj;

bool ok(int i,int j){
  return(i>0&&i<=n&&j>0&&j<=m);
}

void dfs(int ui,int uj,int pi,int pj){
  //cout<<ui<<' '<<uj<<' '<<pi<<' '<<pj<<endl;
  if(vis[2][ui][uj])return ;
  if(vis[1][ui][uj]&&pi!=-1){
    vis[2][ui][uj]=1;
    return ;
  }
  vis[1][ui][uj]=1;

  for(int i=0;i<4;++i){
    int vi=ui+td[i],vj=uj+tc[i];
    if(ok(vi,vj))dfs(vi,vj,ui,uj);
  }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>n>>m;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      char x; cin>>x;
      if(x=='X')vis[1][i][j]=1;
    }
  }
  cin>>si>>sj>>fi>>fj;

  dfs(si,sj,-1,-1);
  //cout<<vis[2][fi][fj];
  cout<<(vis[2][fi][fj]?"YES":"NO");
}
