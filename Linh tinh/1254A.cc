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

const string ANS="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int td[4]={0,0,1,-1};
const int tc[4]={1,-1,0,0};
char a[105][105];
char ans[105][105];
int n,m,k,t;

signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		int cnt=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>a[i][j];
				if(a[i][j]=='R')++cnt;
			}
		}
		
		vector<pair<int,int>> grid;
		bool ok=1;
		for(int i=0;i<n;++i){
			if(ok){for(int j=0;j<m;++j)grid.pb({i,j});}
			else {for(int j=m-1;j>=0;--j)grid.pb({i,j});}
			
			ok=!ok;
		}
		
		int each=cnt/k,extra=(cnt%k==0?0:1);
		for(int i=0;i<k;++i){
			int cur=0;
			while(1){
				int ui=grid.back().fi,uj=grid.back().se;
				grid.pop_back();
				ans[ui][uj]=ANS[i];
				if(a[ui][uj]=='R')--cnt,++cur;
				
				if(cur<each)continue;
				if(each*(k-i-1)<=cnt&&cnt<=(each+extra)*(k-i-1))break;
			}
		}
		
		while(!grid.empty()){
			int ui=grid.back().fi,uj=grid.back().se;
			grid.pop_back();
			ans[ui][uj]=ANS[k-1];
		}
		
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}