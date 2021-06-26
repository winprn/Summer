#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int td[4]={0,0,1,-1};
const int tc[4]={1,-1,0,0};
int a[505][505];
bool mark[505][505],vis[505][505];
int n,m,total,si=-1,sj;

bool ok(int i,int j){
    return (i>=0&&i<n&&j>=0&&j<m);
}

bool check(int x){
    memset(vis,0,sizeof vis);
    queue<pair<int,int>>q;
    int cnt=1;
    q.push({si,sj});
    vis[si][sj]=1;
    while(!q.empty()){
        int ui=q.front().fi;
        int uj=q.front().se;
        q.pop();
        for(int i=0;i<4;++i){
            int vi=ui+td[i];
            int vj=uj+tc[i];
            if(ok(vi,vj)&&abs(a[vi][vj]-a[ui][uj])<=x&&!vis[vi][vj]){
                vis[vi][vj]=1;
                if(mark[vi][vj])++cnt;
                q.push({vi,vj});
            }
        }
    }

    return cnt==total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("run.inp", "r", stdin);
    freopen("run.out", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>a[i][j];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int x;cin>>x;
            if(x){
                if(si==-1)si=i,sj=j;
                ++total;
                mark[i][j]=1;
            }
        }
    }

    int l=0,r=2e9;
    while(r>l){
        int m=l+(r-l+1)/2;
        if(check(m))r=m-1;
        else l=m;
    }
    if(r==2e9)cout<<0<<endl;
    else cout<<r+1<<endl;
}