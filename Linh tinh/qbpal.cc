/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

typedef long double                ld;
typedef long long int              int64;
typedef unsigned long long int     uint64;
typedef std::pair<int, int>        PII;
typedef std::pair<int64, int64>    PLL;
typedef std::vector<int>           VI;
typedef std::vector<long long>     VLL;
// Define For-loop
#define FOR(i, j, k, in)           for (int i = (j); i < (k) ; i += (in))
#define FORW(i, j, k, in)          for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)          for (int i = (j); i >= (k); i -= (in))
// Define Data structure func
#define all(cont)                  cont.begin(), cont.end()
#define rall(cont)                 cont.rbegin(), cont.rend()
#define sz(cont)                   int((cont).size())
#define pb                         push_back
#define mp                         make_pair
#define fi                         first
#define se                         second

const int base = 1000000000;
const int base_digits = 9;
struct bigint {
    static const int base = 1000000000;
    static const int base_digits = 9;

    vector<int> a;
    int sign;

    int size() {
        if(a.empty())return 0;
        int ans=(a.size()-1)*base_digits; int ca=a.back();
        while(ca) ans++,ca/=10;
        return ans;
    }
    string to_string() {
        stringstream ss; ss << *this;
        string s; ss >> s; return s;
    }

    bigint(): sign(1) {}
    bigint(long long v) { *this = v; }
    bigint(const string &s) { read(s); }

    void operator=(const bigint &v) { sign = v.sign; a = v.a; }
    void operator=(long long v) {
        sign = 1; a.clear();
        if (v < 0) sign = -1, v = -v;
        for (; v > 0; v = v / base) a.pb(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < max(sz(a), sz(v.a)) || carry; ++i) {
                if (i == sz(res.a)) res.a.pb(0);
                res.a[i] += carry + (i < sz(a) ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry) res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) sz(v.a) || carry; ++i) {
                    res.a[i] -= carry + (i < (int) sz(v.a) ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0) sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < sz(a) || carry; ++i) {
            if (i == sz(a)) a.pb(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this; res *= v; return res;
    }

    void operator*=(long long v) {
        if (v < 0) sign = -sign, v = -v;
        if(v > base) {
            *this = *this * (v / base) * base + *this * (v % base);
            return ;
        }
        for (int i = 0, carry = 0; i < sz(a) || carry; ++i) {
            if (i == (int) sz(a)) a.pb(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
        }
        trim();
    }

    bigint operator*(long long v) const {
        bigint res = *this; res *= v; return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(sz(a.a));

        for (int i = sz(a.a) - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = sz(r.a) <= sz(b.a) ? 0 : r.a[sz(b.a)];
            int s2 = sz(r.a) <= sz(b.a) - 1 ? 0 : r.a[sz(b.a) - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign; q.trim();
        r.sign = a1.sign; r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const { return divmod(*this, v).first; }
    bigint operator%(const bigint &v) const { return divmod(*this, v).second; }

    void operator/=(int v) {
        if (v < 0) sign = -sign, v = -v;
        for (int i = sz(a) - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this; res /= v; return res;
    }

    int operator%(int v) const {
        if (v < 0) v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i) m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) { *this = *this + v; }
    void operator-=(const bigint &v) { *this = *this - v; }
    void operator*=(const bigint &v) { *this = *this * v; }
    void operator/=(const bigint &v) { *this = *this / v; }

    bool operator < (const bigint &v) const {
        if (sign != v.sign) return sign < v.sign;
        if (sz(a)!= sz(v.a)) return sz(a) * sign < sz(v.a) * v.sign;
        for (int i = sz(a) - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const { return v < *this; }
    bool operator<=(const bigint &v) const { return !(v < *this); }
    bool operator>=(const bigint &v) const { return !(*this < v); }
    bool operator==(const bigint &v) const { return !(*this < v) && !(v < *this); }
    bool operator!=(const bigint &v) const { return *this < v || v < *this; }

    void trim() {
        while (!a.empty() && !a.back()) a.pop_back();
        if (a.empty()) sign = 1;
    }

    bigint operator-() const { bigint res = *this; res.sign = -sign; return res; }
    bigint abs() const { bigint res = *this; res.sign *= res.sign; return res; }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++) x = x * 10 + s[j] - '0';
            a.pb(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s; stream >> s; v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1) stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < sz(p); i++) p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < sz(a); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.pb(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.pb((int) cur);
        while (!res.empty() && !res.back()) res.pop_back();
        return res;
    }

    typedef vector<long long> vll;
    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++) a2[i] += a1[i];
        for (int i = 0; i < k; i++) b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++) r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++) r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++) res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++) res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++) res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size()) a.pb(0);
        while (b.size() < a.size()) b.pb(0);
        while (a.size() & (a.size() - 1)) a.pb(0), b.pb(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.pb((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};

const int N=1e2+50;
bigint dp[N][N];
string s;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>s;
    int n=(int)s.size();
    s=" "+s;
    for(int i=1;i<=n;++i)dp[i][i]=1;

    for(int k=1;k<=n;++k){
        for(int i=1;i<=n-k;++i){
            int j=i+k;
            dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
            if(s[i]==s[j])dp[i][j]+=dp[i+1][j-1]+1;
        }
    }
    cout<<dp[1][n];
}
