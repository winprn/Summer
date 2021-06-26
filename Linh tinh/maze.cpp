#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int td[4]={0,0,1,-1};
const int tc[4]={1,-1,0,0};
char a[105][105];
int d[1005][105][105],idx[105][105];
int n,x,y,cnt=0;

bool ok(int i,int j){
    return (i>=0&&i<n&&j>=0&&j<n);
}

void dijkstra(int idx,int si,int sj){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{si,sj}});
    d[idx][si][sj]=0;

    while(!pq.empty()){
        int ui=pq.top().se.fi;
        int uj=pq.top().se.se;
        pq.pop();

        for(int i=0;i<4;++i){
            int vi=ui+td[i],vj=uj+tc[i];
            if(ok(vi,vj)){
                if(a[ui][uj]!=a[vi][vj]){
                    if(d[idx][vi][vj]>d[idx][ui][uj]+y){
                        d[idx][vi][vj]=d[idx][ui][uj]+y;
                        pq.push({d[idx][vi][vj],{vi,vj}});
                    }
                }else{
                    if(d[idx][vi][vj]>d[idx][ui][uj]+x){
                        d[idx][vi][vj]=d[idx][ui][uj]+x;
                        pq.push({d[idx][vi][vj],{vi,vj}});
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("maze.inp", "r", stdin);
    freopen("maze.out", "w", stdout);

    cin>>n>>x>>y;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        cin>>a[i][j];
        idx[i][j]=++cnt;
    }

    memset(d,63,sizeof d);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            d[idx[i][j]][i][j]=0;
            dijkstra(idx[i][j],i,j);
        }
    }

    int ans=-1;
    for(int k=1;k<=cnt;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)ans=max(ans,d[k][i][j]);
        }
    }
    cout<<ans<<endl;
}