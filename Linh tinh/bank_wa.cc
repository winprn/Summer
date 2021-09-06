#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//add more if needed-------------------------------------------------//
#define fio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rfopen(s) freopen(s, "r", stdin)
#define wfopen(s) freopen(s, "w", stdout)
#define len(a) int(a.size())
#define forw(i, a, b, s) for(int i = a; i < b; i += s)
#define revs(i, a, b, s) for(int i = a; i > b; i -= s)
#define PB push_back
#define EB emplace_back
#define ever ;;
#define FS first
#define SC second
#define PI acos(-1.0)
#define resarr(a) memset(a, 0, sizeof a);
//bit
#define CNTBIT(x) __builtin_popcount(x)
#define ODDBIT(x) __builtin_parity(x)
#define MASK(i) (1<<(i))
#define BIT(x, i) x&MASK(i)
#define SUBSET(big, small) (((big)&(small))==(small))
using namespace std;
namespace io {
    const int SIZE = (1 << 20) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
    inline void flush() { fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; } // print the remaining part
    inline void putc(char x) { *oS++ = x; if (oS == oT) flush (); } // putchar
    template<typename A> inline bool read (A &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1; else if (c == EOF) return 0;
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
    template<typename A> inline bool write(A x) {
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
    struct Flusher_ {~Flusher_(){ flush(); }} io_flusher_;
} using io::read; using io::putc; using io::write;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<ll, ll> pll;
typedef pair<pii, int> pii_i;
typedef pair<int, pii> pi_ii;
typedef pair<int, pll> pi_ll;
typedef pair<float, int> pfi;
typedef pair<ull, pii> pull_ii;
typedef pair<float, pii> pfii;
//add more if needed-------------------------------------------------//
const int INF = 1e9 + 7;
const ll INF64 = 1e18 + 7;
const float fINF = 340282346638528859811704183484516925439.0000000000000000;
const int N = 1e4 + 7; ///replace N with the given limit
const int MOD = 1e9 + 7; ///replace this with mod value
pii a[N];
int n, t;

int main(){
    freopen("i","r",stdin);
    freopen("o","w",stdout);
    fio;
    ///codes:
    read(n, t);
    for (int i = 0; i < n; i++){
        read(a[i].SC, a[i].FS);
        a[i].SC = -a[i].SC;
    }
    sort(a, a + n);
    int ptr = 0;
    int ans = 0;
    for (int t = 0; t <= 47; t++){
        while (a[ptr].FS < t && ptr < n) ptr++;
        if (ptr < n){
            ans += -a[ptr].SC;
            ptr++;
        }
    }
    write(ans);
}
