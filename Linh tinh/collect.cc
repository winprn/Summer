#include <bits/stdc++.h>
 
using namespace std;
 
#define nl '\n'
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
 
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

int n;

bool cmp(pair<iii,int> &a, pair<iii,int> &b){
	if(a.fi.fi.fi!=b.fi.fi.fi)return a.fi.fi.fi<b.fi.fi.fi;
	if(a.fi.fi.se!=b.fi.fi.se)return a.fi.fi.se<b.fi.fi.se;
	if(a.fi.se!=b.fi.se)return a.fi.se<b.fi.se;
	
	return a.se<b.se;
}

signed main(){
	read(n);
	iii s,t;
	read(s.fi.fi,s.fi.se,s.se);
	read(t.fi.fi,t.fi.se,t.se);
	
	map<iii,iii> m;
	vector<iii> possible;
	iii u,v;
	while(read(u.fi.fi,u.fi.se,u.se,v.fi.fi,v.fi.se,v.se)){
		m[u]=v;
		possible.pb(u);
	}
	
	map<iii,int> d;
	vector<pair<iii,int>> ans;
	queue<iii> q;
	q.push(s);
	while(!q.empty()){
		u=q.front();
		q.pop();
		
		if(u.fi.fi>=t.fi.fi&&u.fi.se>=t.fi.se&&u.se>=t.se){
			if(d[u]<=n)ans.pb({u,d[u]});
			continue;
		}
		for(auto i:possible){
			v.fi.fi=u.fi.fi-i.fi.fi;
			v.fi.se=u.fi.se-i.fi.se;
			v.se=u.se-i.se;
			if(v.fi.fi<0||v.fi.se<0||v.se<0)continue;
			v.fi.fi+=m[i].fi.fi;
			v.fi.se+=m[i].fi.se;
			v.se+=m[i].se;
			if(v.fi.fi>4||v.fi.se>4||v.se>4)continue;
			if(d[v]>d[u]+1||d[v]==0){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	
	if((int)ans.size()){
		write(ans.size(),nl);
		sort(ans.begin(),ans.end(),cmp);
		auto cur=ans[0];
		write(cur.fi.fi.fi,' ',cur.fi.fi.se,' ',cur.fi.se,' ',cur.se);
		write(nl);
		for(int i=1;i<(int)ans.size();++i){
			auto x=ans[i];
			if(cur.fi.fi.fi==x.fi.fi.fi&&cur.fi.fi.se==x.fi.fi.se&&cur.fi.se==x.fi.se)continue;
			write(x.fi.fi.fi,' ',x.fi.fi.se,' ',x.fi.se,' ',x.se);
			write(nl);
			cur=x;
		}
	}else write(-1,nl);
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}