#include <bits/stdc++.h>

using namespace std;

#define pb push_back
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

const int MX=1e9+7;
vector<pair<string,int>> ans;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    string cmd="";
    int x;
    for(int i=0;i<n;++i){
        cin>>cmd;
        if(cmd!="removeMin"){
            cin>>x;
            if(cmd=="insert")pq.push(x),ans.pb({"insert",x});
            else{
                while(!pq.empty()&&pq.top()<x)ans.pb({"removeMin",MX}),pq.pop();
                
                if(pq.empty())pq.push(x),ans.pb({"insert",x});
                else if(pq.top()!=x)pq.push(x),ans.pb({"insert",x});

                ans.pb({"getMin",x});
            }
        }else{
            if(!pq.empty())pq.pop();
            else ans.pb({"insert 1",MX});

            ans.pb({"removeMin",MX});
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.fi;
        if(i.se!=MX)cout<<' '<<i.se;
        cout<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}