#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int td[4]={0,0,1,-1};
const int tc[4]={1,-1,0,0};
const int N=1e3+10;
vector<pair<int,int>> pos;
char a[N][N];
int d[N][N];
int n,m,ei,ej,si,sj;

bool ok(int i,int j){
    return(i>=0&&i<n&&j>=0&&j<m&&a[i][j]!='T');
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m;
    memset(d,0x3f,sizeof d);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
            if(a[i][j]=='E'){
                ei=i,ej=j;
            }else if(a[i][j]=='S'){
                si=i,sj=j;
            }else if(a[i][j]>'0'&&a[i][j]<='9'){
                pos.pb({i,j});
            }
        }
    }

    queue<pair<int,int>> q;
    q.push({ei,ej});
    d[ei][ej]=0;
    while(!q.empty()){
        int ui=q.front().fi;
        int uj=q.front().se;
        q.pop();

        for(int i=0;i<4;++i){
            int vi=ui+td[i];
            int vj=uj+tc[i];
            if(ok(vi,vj)&&d[vi][vj]>d[ui][uj]+1){
                d[vi][vj]=d[ui][uj]+1;
                q.push({vi,vj});
            }
        }
    }

    int ans=0;
    for(auto i:pos){
        if(d[i.fi][i.se]<=d[si][sj])ans+=(a[i.fi][i.se]-'0');
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}