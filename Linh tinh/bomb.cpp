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

const int td[4]={0,0,1,-1};
const int tc[4]={1,-1,0,0};
int times[505][505];
int n;

bool ok(int i,int j){
	return(i>=0&&j>=0);
}

signed main(){
	read(n);
	for(int i=0;i<=500;++i)for(int j=0;j<=500;++j)times[i][j]=1e9;
	for(int i=0;i<n;++i){
		int x,y,t; read(x,y,t);
		times[x][y]=t;
		for(int j=0;j<4;++j){
			int vi=x+td[j];
			int vj=y+tc[j];
			if(ok(vi,vj))times[vi][vj]=t;
		}
	}
	
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	int ans=-1;
	if(times[0][0]>0)pq.push({0,{0,0}});
	while(!pq.empty()){
		int cur=pq.top().fi;
		int ui=pq.top().se.fi;
		int uj=pq.top().se.se;
		pq.pop();
		
		if(times[ui][uj]==1e9){ans=cur;break;}
		for(int i=0;i<4;++i){
			int vi=ui+td[i];
			int vj=uj+tc[i];
			if(ok(vi,vj)){
				if(times[vi][vj]>cur+1){
					pq.push({cur+1,{vi,vj}});
				}
			}
		}
	}
	write(ans,'\n');
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}