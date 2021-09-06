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

int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    if(n<=3)cout<<"NO";
    else{
        cout<<"YES"<<endl;
        if(n==4){
            cout<<"1 * 2 = 2"<<endl;
            cout<<"3 * 2 = 6"<<endl;
            cout<<"6 * 4 = 24"<<endl;
        }else if(n==5){
            cout<<"4 * 5 = 20"<<endl;
            cout<<"20 + 3 = 23"<<endl;
            cout<<"23 + 2 = 25"<<endl;
            cout<<"25 - 1 = 24"<<endl;
        }else if(n==7){
            cout<<"3 + 4 = 7"<<endl;
            cout<<"7 + 5 = 12"<<endl;
            cout<<"12 + 6 = 18"<<endl;
            cout<<"18 + 7 = 25"<<endl;
            cout<<"25 - 2 = 23"<<endl;
            cout<<"23 + 1 = 24"<<endl;
        }else{
            if(n%2==0){
                cout<<"1 * 2 = 2"<<endl;
                cout<<"2 * 3 = 6"<<endl;
                cout<<"6 * 4 = 24"<<endl;

                for(int i=5;i<=n;i+=2){
                    cout<<i+1<<" - "<<i<<" = 1"<<endl;
                    cout<<"24 * 1 = 24"<<endl;
                }
            }else{
                cout<<"2 * 3 = 6"<<endl;
                cout<<"6 * 4 = 24"<<endl;
                cout<<"8 - 6 = 2"<<endl;
                cout<<"9 - 7 = 2"<<endl;
                cout<<"2 + 2 = 4"<<endl;
                cout<<"4 + 1 = 5"<<endl;
                cout<<"5 - 5 = 0"<<endl;
                
                for(int i=10;i<=n;i+=2){
                    cout<<i+1<<" - "<<i<<" = 1"<<endl;
                    cout<<"24 * 1 = 24"<<endl;
                }
                cout<<"24 - 0 = 24"<<endl;
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}