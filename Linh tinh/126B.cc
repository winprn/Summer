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

string s;
vector<int> z;
int n;

void z_func(){
	z.resize(n);
	int l=0,r=0;
	for(int i=1;i<n;++i){
		z[i]=max(0,min(z[i-l],r-i+1));
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
			l=i,r=i+z[i],++z[i];
		}
	}
}

signed main(){
	cin>>s;
	n=(int)s.size();
	z_func();
	int mx=-1;
	for(int i=1;i<n;++i){
		mx=max(mx,min(z[i],n-i-1));
	}
	// for(int i=1;i<n;++i)cout<<z[i]<<' ';
	// cout<<endl;
	
	int idx=-1;
	for(int i=n-mx;i<n;++i){
		if(i+z[i]==n){idx=i;break;}
	}
	
	if(idx==-1)cout<<"Just a legend";
	else cout<<s.substr(idx,n);
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}