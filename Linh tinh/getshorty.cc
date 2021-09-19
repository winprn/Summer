/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
vector<pair<int,long long>> adj[N];
long long d[N];
int n,m;

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(4);
  cout<<fixed;
  freopen("i", "r", stdin);
  freopen("o", "w", stdout);

  while(cin>>n>>m,n){
    for(int i=0;i<=n;++i)d[i]=-1,adj[i].clear();
    for(int i=0;i<m;++i){
      int u,v; cin>>u>>v;
      long double f; cin>>f;
      long long tmp=f*1000;
      adj[u].push_back({v,tmp});
      adj[v].push_back({u,tmp});
    }

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({1000,0});
    d[0]=1000;
    while(!pq.empty()){
      int u=pq.top().second;
      pq.pop();

      for(auto v:adj[u]){
//        if(u==1){
//          cout<<v.first<<' '<<v.second<<endl;
//        }
        if(d[v.first]<d[u]*v.second/1000){
          d[v.first]=d[u]*v.second/1000;
          pq.push({d[v.first],v.first});
        }
      }
    }
    cout<<d[n-1]/1000.<<endl;
  }
}
