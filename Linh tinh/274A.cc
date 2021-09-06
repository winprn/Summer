#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

namespace io {
	const int SIZE = (1 << 20) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush() { fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
	// putchar
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
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::read; using io::putc; using io::write;

const int N=1e5+10;
int a[N];
int n,k;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    read(n),read(k);
    for(int i=0;i<n;++i)read(a[i]);
    sort(a,a+n);

    set<int> s1,s2;
    s1.insert(a[0]);
    for(int i=1;i<n;++i){
        if(a[i]%k==0){
            auto it=s1.lower_bound(a[i]/k);
            if(*it==a[i]/k)s2.insert(a[i]);
            else s1.insert(a[i]);
        }else s1.insert(a[i]);
    }
    write(max(s1.size(),s2.size()));

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}