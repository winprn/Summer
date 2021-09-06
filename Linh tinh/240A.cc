#include <bits/stdc++.h>

using namespace std;

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

bitset<(int)1e9+10> mark;
int n,k;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>k;
    if(n==1)cout<<(k==0?1:-1);
    else if(k<n/2)cout<<-1;
    else{
        int a=k-((n-2)/2);
        cout<<a<<' '<<a*2<<' ';
        mark[a]=mark[a*2]=1;
        int cur=1;
        for(int i=0;i<((n-2)/2);++i){
            while(mark[cur])++cur;
            cout<<cur<<' ';
            mark[cur]=1;
            while(mark[cur+1])++cur;
            cout<<cur+1<<' ';
            mark[cur+1]=1;
        }

        if(n&1){while(mark[cur])++cur;cout<<cur;}
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}