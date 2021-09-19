/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int td[4]={0,0,1,-1};
const int tc[4]={1,-1,0,0};
const int N=1e3+10;
char a[N][N];
bool vis[N][N],mark[2];
int n,m;

bool ok(int i,int j){
  return(i>=0&&i<n&&j>=0&&j<m&&!vis[i][j]&&a[i][j]=='#');
}

void bfs(int si,int sj){
  queue<pair<int,int>> q;
  q.push({si,sj});
  while(!q.empty()){
    int ui=q.front().first;
    int uj=q.front().second;
    q.pop();

    for(int i=0;i<4;++i){
      int vi=ui+td[i],vj=uj+tc[i];
      if(ok(vi,vj)){
        vis[vi][vj]=1;
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

  cin>>n>>m;
  for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>a[i][j];

  bool OK=1;
  for(int i=0;i<n;++i){
    int cnt=0;
    for(int j=0;j<m;++j){
      if(a[i][j]=='#'&&(!j||a[i][j-1]=='.')&&++cnt>1)OK=0;
    }
    if(!cnt)mark[0]=1;
  }
  for(int j=0;j<m;++j){
    int cnt=0;
    for(int i=0;i<n;++i){
      if(a[i][j]=='#'&&(!i||a[i-1][j]=='.')&&++cnt>1)OK=0;
    }
    if(!cnt)mark[1]=1;
  }
  if(mark[0]!=mark[1])OK=0;

  if(!OK)cout<<-1;
  else{
    int ans=0;
    for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
        if(!vis[i][j]&&a[i][j]=='#'){
          ++ans;
          bfs(i,j);
        }
      }
    }
    cout<<ans;
  }
}
