#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef double ld;

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

const ld EPS=1e-7;
int a[1005],b[1005];
int n,k;

bool ok(ld x){
    ld w=k+x;
    for(int i=0;i<n-1;++i){
        if(w<=0||x<=0)return 0;
        if(x<w/(a[i]*1.))return 0;
        x-=w/(a[i]*1.);
        w-=w/(a[i]*1.);
        if(x<w/b[i+1]*1.)return 0;
        x-=w/(b[i+1]*1.);
        w-=w/(b[i+1]*1.);
    }

    if(w<=0||x<=0)return 0;
    if(x<w/(a[n-1]*1.))return 0;
    x-=w/(a[n-1]*1.);
    w-=w/(a[n-1]*1.);
    if(w<=0||x<=0)return 0;
    if(x<w/(b[0]*1.))return 0;
    return 1;
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];

    ld l=0,r=1e9+7;
    ld ans=-1;
    for(int i=0;i<=60;++i){
        ld m=(l+r)/2.;
        if(ok(m)){
            ans=m;
            r=m;
        }else l=m;
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}