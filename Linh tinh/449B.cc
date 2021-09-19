/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple

const int N=1e5+10;
vector<pair<pair<int,long long>,int>> adj[N];
long long d[N];
int lst[N];
int n,m,k;

void dijkstra(){
  for(int i=1;i<=n;++i)d[i]=1e18;
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
  pq.push(mt(0,0,1));
  while(!pq.empty()){
    int u=get<2>(pq.top());
    long long dd=get<0>(pq.top());
    int t=get<1>(pq.top());
    pq.pop();

    if(d[u]==1e18){
      d[u]=dd;
      if(t==2)--k;
      for(auto v:adj[u]){
        if(d[v.first.first]==1e18){
          pq.push(mt(d[u]+v.first.second,v.second,v.first.first));
        }
      }
    }
  }
//  for(int i=1;i<=n;++i)cout<<d[i]<<' ';
//  cout<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>n>>m>>k;
  for(int i=0;i<m;++i){
    int u,v,w; cin>>u>>v>>w;
    adj[u].push_back({{v,w},1});
    adj[v].push_back({{u,w},1});
  }
  for(int i=0;i<k;++i){
    int u,w; cin>>u>>w;
    adj[1].push_back({{u,w},2});
    adj[u].push_back({{1,w},2});
  }

  dijkstra();
  cout<<k;
}
