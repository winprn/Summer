#include<bits/stdc++.h>
#include<ext/numeric>
#define fastIO                  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, j, k, in)		for (int i = (j); i < (k); i += (in))
#define FORW(i, j, k, in)		for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)		for (int i = (j); i >= (k); i -= (in))
#define RFORW(i, j, k, in)		for (int i = (j); i > (k); i -= (in))
#define sz(arr)                 ((int)(arr).size())
#define pb                      push_back
#define fi						first
#define se						second
#define mp						make_pair

using namespace std;
using namespace __gnu_cxx;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<pii,int> piii;
typedef vector<pii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

const int inf=INT_MAX-(13*7);
const int N=300;
vi adj[N];
int n,m;
int res=0,ans=0;
int s1,s2;
bool d[N][2],dn[N][2];
int main(){
  freopen("age.inp","r",stdin);
  freopen("age.out","w",stdout);
  fastIO;
  cin>>n>>m;
  FORW(i,1,n,1) d[i][0]=d[i][1]=inf;
  cin>>s1>>s2;
  FORW(i,1,m,1){
      int u,v;
      cin>>u>>v;
      adj[u].pb(v);
      //adj[v].pb(u);
  }
  dn[s1][0]=1;
  dn[s2][1]=1;
  while(res<=20*n){

      FORW(i,1,n,1){
          d[i][0]=d[i][1]=0;
          d[i][0]=dn[i][0];
          d[i][1]=dn[i][1];
          dn[i][0]=dn[i][1]=0;
          if(d[i][0]==1&&d[i][1]==1){ans=res; break;}
      }
      if(ans) break;
      FORW(i,1,n,1){
          if(d[i][0]){
              for(auto j:adj[i]) dn[j][0]=1;
          }
          if(d[i][1]){
              for(auto j:adj[i]) dn[j][1]=1;
          }
      }
      ++res;
  }
  cout<<(res>20*n?-1:ans);
}
