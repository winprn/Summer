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
set<int> id[N*10];
int st[2][8*N];
int n;

int _gcd(int a,int b){
	if(!b)return a;
	return _gcd(b,a%b);
}

void update(int t,int id,int l,int r,int idx,int val){
	if(idx<l||idx>r)return;
	if(l==r){
		st[t][id]=val;
		return;
	}
	
	int m=(l+r)/2;
	update(t,id*2,l,m,idx,val);
	update(t,id*2+1,m+1,r,idx,val);
	if(!t)st[t][id]=min(st[t][id*2],st[t][id*2+1]);
	else st[t][id]=_gcd(st[t][id*2],st[t][id*2+1]);
}

int get(int t,int id,int l,int r,int tl,int tr){
	if(tl>r||tr<l){
		if(!t)return 1e9;
		return 0;
	}
	if(tl<=l&&tr>=r)return st[t][id];
	
	int m=(l+r)/2;
	if(!t)return min(get(t,id*2,l,m,tl,tr),get(t,id*2+1,m+1,r,tl,tr));
	return _gcd(get(t,id*2,l,m,tl,tr),get(t,id*2+1,m+1,r,tl,tr));
}

bool ok(int i,int x){
	bool tmp=0;
    for(int k=1;k*k<=x;++k){
    	if(x%k==0){
    		auto it=id[k].upper_bound(i);
		    if(it!=id[k].end()){
		        tmp=(get(1,1,1,n,i,*it)==get(0,1,1,n,i,*it));
		    }
		    
		    it=id[x/k].upper_bound(i);
		    if(it!=id[k].end())tmp=(tmp||(get(1,1,1,n,i,*it)==get(0,1,1,n,i,*it)));
    	}
    }

    return tmp;
}

signed main(){
    freopen("capso.inp","r",stdin);
    freopen("capso.out","w",stdout);

	read(n);
	for(int i=1;i<=n;++i){
		int x; read(x);
        id[x].insert(i);
		update(0,1,1,n,i,x);
		update(1,1,1,n,i,x);
	}
	
	vector<int> ans;
	int l=1,r=1,mx=-1;
	while(l<=n){
		while(r<=n&&(get(1,1,1,n,l,r)==get(0,1,1,n,l,r)||ok(r,get(1,1,1,n,l,r))))++r;
		
		--r;
		// cout<<l<<' '<<r<<endl;
		// cout<<get(1,1,1,n,l,r)<<' '<<get(0,1,1,n,l,r)<<endl;
		int len=r-l;
		if(len>mx){
			ans.clear();
			ans.pb(l);
			mx=len;
		}else if(len==mx){
			ans.pb(l);
		}
		++l;r=max(r,l);
	}
	write((int)ans.size(),' ',mx,nl);
	for(int i:ans)write(i,' ');
	write(nl);
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
}