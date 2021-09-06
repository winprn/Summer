#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
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

const int N=2e5+10;
pair<ll,ll> a[N];
ll b[N],c[N];
ll n,m,k,x,s;

ll get(ll x){
    //cout<<x<<endl;
    int l=0,r=k,ans=-1;
    while(r>l){
        int m=(r+l+1)/2;
        //cout<<m<<' '<<c[m]<<endl;
        if(c[m]<=x)ans=m,l=m;
        else r=m-1;
    }

    return b[l];
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m>>k>>x>>s;
    a[0].fi=x,a[0].se=0,b[0]=c[0]=0;
    for(int i=1;i<=m;++i)cin>>a[i].fi;
    for(int i=1;i<=m;++i)cin>>a[i].se;
    for(int i=1;i<=k;++i)cin>>b[i];
    for(int i=1;i<=k;++i)cin>>c[i];

    ll ans=n*x;
    for(int i=0;i<=m;++i){
        ll tmp=s-a[i].se;
        if(tmp<0)continue;
        ans=min(ans,(n-get(tmp))*a[i].fi);
    }

    if(s>=c[k-1])ans=min(ans,1LL*(n-b[k-1])*x);
    cout<<ans;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}