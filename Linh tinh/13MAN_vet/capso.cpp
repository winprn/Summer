#include <bits/stdc++.h>
 
using namespace std;
 
#define nl '\n'
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

const int N=3e5+10;
int a[N],st[N][30],loga2[N];
int n;

int _gcd(int a,int b){
	if(!b)return a;
	return _gcd(b,a%b);
}

int get(int l,int r){
	int i=loga2[r-l+1];
	return _gcd(st[l][i],st[r-(1<<i)+1][i]);
}

signed main(){
	freopen("capso.inp","r",stdin);
	freopen("capso.out","w",stdout);

	read(n);
	for(int i=0;i<n;++i){
		int x; read(x);
		a[i]=x;
		st[i][0]=a[i];
	}
	
	loga2[1]=0;
	for(int i=2;i<=n;++i){
		loga2[i]=loga2[i/2]+1;
	}
	for(int j=1;j<=22;++j){
		for(int i=0;i+(1<<j)<=n;++i){
			st[i][j]=_gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	
	vector<int> ans;
	int tl,tr,l,r,mx=-1;
	for(int i=0;i<n;++i){
		int mn=a[i];
		tl=0,tr=i,l=-1;
		for(int j=0;j<=32;++j){
			int m=(tr+tl)/2;
			if(get(m,i)>=mn)tr=m-1,l=m;
			else tl=m+1;
		}
		if(l==-1)continue;
		
		tl=i,tr=n-1,r=-1;
		for(int j=0;j<=32;++j){
			int m=(tr+tl)/2;
			if(get(i,m)>=mn)tl=m+1,r=m;
			else tr=m-1;
		}
		if(r==-1)continue;
		
		//l=max(0,l),r=min(n-1,r);
		//cout<<i<<' '<<l<<' '<<r<<endl;
		if(r-l>mx){
			ans.clear();
			ans.pb(l+1);
			mx=r-l;
		}else if(r-l==mx)ans.pb(l+1);
	}
	
	write((int)ans.size(),' ',mx,nl);
	for(int i:ans)write(i,' ');
	write(nl);
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}