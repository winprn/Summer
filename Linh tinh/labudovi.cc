#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;
typedef pair<int,int> pii;

const int td[4]={0,0,1,-1};
const int tc[4]={1,-1,0,0};
const int N=2e3+10;
int cost[N][N],d[N][N];
int n,m,si=-1,sj,ei,ej;

bool ok(int i,int j){
    return (i>=0&&i<n&&j>=0&&j<m);
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m;
    queue<pii>q;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char x;cin>>x;
            if(x=='.'){
                cost[i][j]=0;
                q.push({i,j});
            }else if(x=='L'){
                cost[i][j]=0;
                q.push({i,j});
                if(si==-1)si=i,sj=j;
                else ei=i,ej=j;
            }else cost[i][j]=1e9;
        }
    }

    while(!q.empty()){
        int ui=q.front().fi;
        int uj=q.front().se;
        q.pop();

        for(int i=0;i<4;++i){
            int vi=ui+td[i],vj=uj+tc[i];
            if(ok(vi,vj)&&cost[vi][vj]>cost[ui][uj]+1){
                cost[vi][vj]=cost[ui][uj]+1;
                q.push({vi,vj});
            }
        }
    }

    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m;++j)cout<<cost[i][j]<<' ';
    //     cout<<endl;
    // }

    memset(d,0x3f,sizeof d);
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
    pq.push({0,{si,sj}});
    d[si][sj]=0;
    while(!pq.empty()){
        int ui=pq.top().se.fi;
        int uj=pq.top().se.se;
        pq.pop();

        if(ui==ei&&uj==ej)break;
        for(int i=0;i<4;++i){
            int vi=ui+td[i],vj=uj+tc[i];
            if(ok(vi,vj)){
                if(d[vi][vj]==-1){
                    d[vi][vj]=max(cost[vi][vj],d[ui][uj]);
                    pq.push({d[vi][vj],{vi,vj}});
                }else if(d[vi][vj]>max({d[ui][uj],cost[vi][vj]})){
                    d[vi][vj]=max(cost[vi][vj],d[ui][uj]);
                    pq.push({d[vi][vj],{vi,vj}});
                }
            }
        }
    }
    cout<<d[ei][ej]<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif

}