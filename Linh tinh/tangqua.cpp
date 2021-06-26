// #include <bits/stdc++.h>

// using namespace std;

// #define ms(a,x) memset(a,(x),sizeof a)
// #define MOD 1000000007

// typedef long long ll;

// int c[3005][3005],f[3005][3005],trace[3005];
// int n,m,t,flow;

// bool bfs(){
//     ms(trace,-1);
//     queue<int>q;
//     q.push(0);
//     trace[0]=n+1;

//     while(!q.empty()){
//         int u=q.front();
//         q.pop();

//         for(int v=1;v<=n;++v){
//             if(trace[v]==-1&&c[u][v]>f[u][v]){
//                 trace[v]=u;
//                 if(v==n)return 1;
//                 q.push(v);
//             }
//         }
//     }
    
//     return 0;
// }

// void inc(){
//     int delta=1e9,u,v=n;
//     do{
//         u=trace[v];
//         delta=min(delta,c[u][v]-f[u][v]);
//         v=u;
//     }while(v!=0);
//     v=n,flow+=delta;

//     do{
//         u=trace[v];
//         f[u][v]+=delta;
//         f[v][u]-=delta;
//         v=u;
//     }while(v!=0);
// }

// int main() {
//     freopen("tangqua.inp", "r", stdin);
//     freopen("tangqua.out", "w", stdout);

//     cin>>t;
//     while(t--){
//         cin>>n>>m;
//         ms(c,0),ms(f,0);
//         flow=0;
//         for(int i=0;i<m;++i){
//             int u,v;cin>>u>>v;
//             c[u][v+n]=c[v][u+n]=1;
//             // adj[u].pb(v);
//             // adj[v].pb(u);
//         }
//         for(int i=1;i<=n;++i)c[0][i]=1e9;
//         for(int i=n+1;i<=2*n;++i)c[i][n+n+1]=1e9;
//         n=2*n+1;

//         while(bfs())inc();
//         if(flow>=n-1)cout<<'Y'<<endl;
//         else cout<<'N'<<endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("i","r",stdin);

    mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
    // mt19937 rng(6);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<bool>> mat(n, vector<bool>(n));
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mat[u][v] = mat[v][u] = true;
    }

    // if (n <= 20) {
    //     auto solve = [&] (auto &self, int u, int mask) -> bool {
    //         if (mask == (1 << n) - 1) {
    //             if (u == 0) {
    //                 cout << u + 1 << " ";
    //                 return true;
    //             }
    //             return false;
    //         }
    //         for (int v : adj[u])
    //             if (~mask & (1 << v) && self(self, v, mask | (1 << v))) {
    //                 cout << u + 1 << " ";
    //                 return true;
    //             }
    //         return false;
    //     };
    //     solve(solve, 0, 0);
    //     cout << "\n";
    //     return 0;
    // }

    bool OK=1;
    for (int rep=0; rep<100; rep++) {
        vector<int> ret(n);
        iota(ret.begin() + 1, ret.end(), 1);
        shuffle(ret.begin() + 1, ret.end(), rng);
        ret.push_back(0);
        bool done = false;
        if (rep == 99)
            done = true;
        while (!done) {
            done = true;
            for (int i=0; i<n; i++)
                if (!mat[ret[i]][ret[i+1]]) {
                    bool ok = false;
                    for (int j=i+1; j<n; j++)
                        if (mat[ret[j]][ret[j+1]] && mat[ret[i]][ret[j]] && mat[ret[i+1]][ret[j+1]]) {
                            reverse(ret.begin() + i + 1, ret.begin() + j + 1);
                            ok = true;
                            break;
                        }
                    if (!ok) {
                        for (int j=0; j+1<i; j++)
                            if (mat[ret[j]][ret[j+1]] && mat[ret[i]][ret[j]] && mat[ret[i+1]][ret[j+1]]) {
                                int l = i + 1, r = j;
                                vector<bool> vis(n);
                                while (!vis[l] && !vis[r]) {
                                    swap(ret[l], ret[r]);
                                    vis[l] = vis[r] = true;
                                    if (++l == n)
                                        l = 0;
                                    if (--r == -1)
                                        r = n - 1;
                                }
                                ret[n] = ret[0];
                                ok = true;
                                break;
                            }
                        if (!ok)
                            OK=0;
                            break;
                    }
                    done = false;
                }
        }
        // for (int i=0; i<=n; i++)
        //     cout << ret[i] + 1 << " ";
        // cout << "\n";
    }
    if(OK)cout<<'Y';
        else cout<<'N';
        cout<<endl;

    return 0;
}
