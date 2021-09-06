#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
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

const int N=1e3+10;
pair<int, double> a[N];
double dp[N][N];
double l;
int n,w,cnt=1;

double _dp(int i,int j,double cur){
    if(i==n)return cur;

    double& ans=dp[i][j];
    if(ans!=-1.)return ans;
    double c=1e9,d;
    if(j+a[i].fi<=w)c=_dp(i+1,j+a[i].fi,max(a[i].se,cur));
    d=cur+_dp(i+1,a[i].fi,a[i].se);
    //cout<<i<<' '<<c<<' '<<d<<endl;
    if(c>d){
        c=d;
        ++cnt;
    }

    return ans=c;
}

int main() {
    cout.precision(2);
    cout<<fixed;
    freopen("cargroup.inp", "r", stdin);
    freopen("cargroup.out", "w", stdout);

    cin>>n>>w>>l;
    for(int i=0;i<n;++i){
        cin>>a[i].fi>>a[i].se;
        a[i].se=l/a[i].se;
    }

    for(int i=0;i<=n;++i)for(int j=0;j<=w;++j)dp[i][j]=-1.;
    cout<<_dp(1,a[0].fi,a[0].se)<<endl;
    
    //cout<<cnt<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}