#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const string s="codeforces";
int cnt[15];
ll n,len=1;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<12;++i)cnt[i]=1;
    while(len<n){
        for(int i=0;i<(int)s.size()&&len<n;++i){
            len/=cnt[i];
            ++cnt[i];
            len*=cnt[i];
        }
    }

    for(int i=0;i<(int)s.size();++i){
        for(int j=0;j<cnt[i];++j)cout<<s[i];
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}