#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

namespace io{
    const int SIZE = (1 << 20) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
    inline void flush() { fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
    inline void putc(char x) { *oS++ = x; if (oS == oT) flush (); }
    template<typename A>
    inline bool read (A &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1; else if (c==EOF) return 0;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
        return 1;
    }

    inline bool read(char &x) {
        while((x = gc()) == ' ' || x == '\n' || x == '\r'); return x != EOF;
    }

    inline bool read(string& x) {
        while ((c = gc()) == '\n' || c == ' '|| c == '\r'); if (c == EOF) return 0; x.clear();
        while (!(c == '\n' || c == ' ' || c == '\r' || c == EOF)) x.push_back(c), c = gc(); return 1;
    }

    template<typename A,typename ...B>
    inline bool read(A &x, B &...y){ return read(x) + read(y...); }
    template<typename A>

    inline bool write(A x) {
        if (!x) putc('0'); if (x < 0) putc ('-'), x = -x;
        while (x) qu[++qr] = x % 10 + '0', x /= 10;
        while (qr) putc(qu[qr--]);
        return 0;
    }

    inline bool write(char x) { putc(x); return 0; }
    inline bool write(const char *x){ while (*x){ putc(*x); ++x; } return 0; }
    inline bool write(char *x){ while (*x){ putc(*x); ++x; } return 0; }
    template<typename A,typename ...B>
    inline bool write(A x,B ...y){ return write(x) || write(y...); }
    struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::read; using io::putc; using io::write;

const int N=4e5+10;
vector<int> adj[N];
int cnt[N];
bool mark[N],vis[N],vis2[N],inqueue[N];
int n,m,t;

void dfs(int u,int p){
    vis[u]=1;
    inqueue[u]=1;
    for(int v:adj[u]){
        cnt[v]++;
        if(inqueue[v])mark[v]=1;
        if(!vis[v])dfs(v,u);
    }
    inqueue[u]=0;
}

void dfs2(int u){
    vis2[u]=1;
    for(int v:adj[u]){
        mark[v]=1;
        if(!vis2[v])dfs2(v);
    }
}

void dfs3(int u){
    vis2[u]=1;
    for(int v:adj[u]){
        cnt[v]++;
        if(!vis2[v])dfs3(v);
    }
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    read(t);
    while(t--){
        read(n,m);
        memset(vis,0,sizeof vis);
        memset(vis2,0,sizeof vis2);
        memset(inqueue,0,sizeof inqueue);
        memset(mark,0,sizeof mark);
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;++i)adj[i].clear();
        for(int i=0;i<m;++i){
            int u,v; read(u,v);
            if(u==v)mark[u]=1;
            else adj[u].pb(v);
        }

        cnt[1]=1;
        dfs(1,-1);

        for(int i=1;i<=n;++i){
            if(vis[i]&&mark[i]&&!vis2[i])dfs2(i);
        }
        memset(vis2,0,sizeof vis2);
        for(int i=1;i<=n;++i){
            if(vis[i]&&cnt[i]>1&&!vis2[i])dfs3(i);
        }       

        for(int i=1;i<=n;++i){
            if(!vis[i])write(0,' ');
            else if(mark[i])write(-1,' ');
            else write(min(cnt[i],2),' ');
        }
        write('\n');
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}