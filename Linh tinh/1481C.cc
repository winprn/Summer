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

const int N=1e5+10;
vector<int> idx[N];
int a[N],b[N],c[N],cnt[N],res[N];
int n,m,t;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            cnt[i]=0;
            idx[i].clear();
        }
        for(int i=0;i<n;++i)cin>>a[i];
        for(int i=0;i<n;++i){
            cin>>b[i];
            if(b[i]!=a[i]){
                idx[b[i]].pb(i);
                cnt[b[i]]++;
            }
        }
        for(int i=0;i<m;++i)cin>>c[i];

        int lst=-1;
        if(cnt[c[m-1]]){
            lst=idx[c[m-1]].back();
            idx[c[m-1]].pop_back();
            --cnt[c[m-1]];
        }else{
            for(int i=0;i<n;++i){
                if(b[i]==c[m-1]){
                    lst=i;
                    break;
                }
            }
        }

        if(lst==-1)cout<<"nO"<<endl;
        else{
            res[m-1]=lst;
            for(int i=0;i<m-1;++i){
                if(cnt[c[i]]==0){
                    res[i]=lst;
                }else{
                    res[i]=idx[c[i]].back();
                    idx[c[i]].pop_back();
                    --cnt[c[i]];
                }
            }

            bool ok=1;
            for(int i=1;i<=n;++i)if(cnt[i]){ok=0;break;}
            if(!ok)cout<<"nO"<<endl;
            else{
                cout<<"yEs"<<endl;
                for(int i=0;i<m;++i)cout<<res[i]+1<<' ';
                cout<<endl;
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}