/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int td[4]={0,0,1,-1};
const int tc[4]={1,-1,0,0};
const int N=1e2+10;
char a[N][N];
int d[3][N][N];
int n,m,ans=1e9,si,sj,fi,fj,t;

bool ok(int i,int j){
  return(i>=0&&i<=n+1&&j>=0&&j<=m+1&&a[i][j]!='*');
}

void bfs(int t,int si,int sj){
  memset(d[t],0x3f,sizeof(d[t]));
  queue<pair<int,int>> q;
  q.push({si,sj});
  d[t][si][sj]=0;

  while(!q.empty()){
    int ui=q.front().first;
    int uj=q.front().second;
    q.pop();

    for(int i=0;i<4;++i){
      int vi=ui+td[i],vj=uj+tc[i];
      if(ok(vi,vj)&&d[t][vi][vj]>d[t][ui][uj]+(a[vi][vj]=='#')){
        d[t][vi][vj]=d[t][ui][uj]+(a[vi][vj]=='#');
        q.push({vi,vj});
      }
    }
  }
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
    si=-1;
    for(int i=0;i<=n+1;++i){
      for(int j=0;j<=m+1;++j){
        if(!i||!j||i>n||j>m)a[i][j]='.';
        else cin>>a[i][j];
        if(a[i][j]=='$'){
          if(si==-1)si=i,sj=j;
          else fi=i,fj=j;
        }
      }
    }
    bfs(0,0,0);
    bfs(1,si,sj);
    bfs(2,fi,fj);

//    for(int i=1;i<=n;++i){
//      for(int j=1;j<=m;++j)cout<<(d[0][i][j]>10?9:d[0][i][j])<<' ';
//      cout<<endl;
//    }
//    cout<<endl;
//    for(int i=1;i<=n;++i){
//      for(int j=1;j<=m;++j)cout<<(d[1][i][j]>10?9:d[1][i][j])<<' ';
//      cout<<endl;
//    }
//    cout<<endl;
//    for(int i=1;i<=n;++i){
//      for(int j=1;j<=m;++j)cout<<(d[2][i][j]>10?9:d[2][i][j])<<' ';
//      cout<<endl;
//    }

    ans=1e9;
    for(int i=1;i<=n;++i){
      for(int j=1;j<=m;++j){
        if(a[i][j]!='*'){
          if(ans>d[1][i][j]+d[2][i][j]-2*(a[i][j]=='#')+d[0][i][j]){
            //cout<<i<<' '<<j<<endl;
            ans=min(ans,d[1][i][j]+d[2][i][j]-2*(a[i][j]=='#')+d[0][i][j]);
          }
        }
      }
    }
    cout<<ans<<endl;
  }
}
