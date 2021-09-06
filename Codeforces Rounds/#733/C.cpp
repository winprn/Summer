#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
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

const int N=1e5+10;
int a[N],b[N];
int n,t;

bool ok(int x){
	ll s1=0,s2=0;
	int cur=(n+x)-((n+x)/4);
	//cout<<cur<<endl;
	for(int i=0;i<min(n,cur);++i){
		s2+=b[i];
	}
	
	if(x>cur)s1=100LL*cur;
	else{
		s1=100LL*x;
		for(int i=0;i<cur-x;++i){
			s1+=a[i];
		}
	}
	
	return s1>=s2;
}

signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=0;i<n;++i)read(a[i]);
		for(int i=0;i<n;++i)read(b[i]);
		sort(a,a+n,greater<int>()),sort(b,b+n,greater<int>());
		// for(int i=0;i<n;++i)cout<<a[i]<<' ';
		// cout<<endl;
		// for(int i=0;i<n;++i)cout<<b[i]<<' ';
		// cout<<endl;
		
		int l=0,r=1e9,ans=-1;
		for(int j=0;j<=32;++j){
			int m=(l+r)/2;
			if(ok(m))ans=m,r=m-1;
			else l=m+1;
		}
		write(ans,'\n');
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}