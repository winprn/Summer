#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

namespace fastIO{
    inline int readChar();
    template <class T = int> inline T readInt();
    template <class T> inline void writeInt( T x, char end = 0 );
    inline void writeChar( int x );
    inline void writeWord( const char *s );
    static const int buf_size = 4096;
    inline int getChar() {
        static char buf[buf_size];
        static int len = 0, pos = 0;
        if (pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
        if (pos == len) return -1;
        return buf[pos++];
    }

    inline int readChar() {
        int c = getChar();
        while (c <= 32 && c != -1) c = getChar();
        return c;
    }

    template <class T> inline T readInt() {
        int s = 1, c = readChar();
        T x = 0;
        if (c == '-') s = -1, c = getChar();
        while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
        return s == 1 ? x : -x;
    }

    static int write_pos = 0;
    static char write_buf[buf_size];
    inline void writeChar( int x ) {
        if (write_pos == buf_size) fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
        write_buf[write_pos++] = x;
    }
    template <class T> inline void writeInt( T x, char end ) {
        if (x < 0) writeChar('-'), x = -x;
        char s[24];
        int n = 0;
        while (x || !n) s[n++] = '0' + x % 10, x /= 10;
        while (n--) writeChar(s[n]);
        if (end) writeChar(end);
    }

    inline void writeWord( const char *s ) {
        while (*s) writeChar(*s++);
    }

    struct Flusher {
        ~Flusher() {
            if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
        }
    } flusher;

}
using namespace fastIO;

vector<int> adj[404],adj2[404];
int a[404][404],d[404];
int n,m;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        a[u][v]=a[v][u]=1;
        adj[u].pb(v);adj[v].pb(u);
    }

    for(int i=1;i<=n;++i)d[i]=1e9;
    if(a[1][n]){
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(a[i][j])continue;
                //cout<<i<<' '<<j<<endl;
                adj2[i].pb(j);adj2[j].pb(i);
            }
            adj[i]=adj2[i];
        }
    }

    queue<int> q;
    q.push(1);
    d[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int v:adj[u]){
            if(d[v]>d[u]+1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }

    cout<<(d[n]==1e9?-1:d[n])<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}