#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=3e5+10;
string s;
int a[N],pref[N],suf[N];
int n,k;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("nguoinhen.inp", "r", stdin);
    freopen("nguoinhen.out", "w", stdout);

    cin>>n>>k;
    --k;
    for(int i=0;i<n;++i)cin>>a[i];
    cin>>s;

    for(int i=1;i<n;++i){
        if(a[i]<a[i-1])continue;
        if(s[i-1]=='T')s[i]='T';
        pref[i]=pref[i-1]+1;
    }
    for(int i=n-2;i>=0;--i){
        if(a[i]<a[i+1])continue;
        if(s[i+1]=='T')s[i]='T';
        suf[i]=suf[i+1]+1;
    }

    int cnt=0,mx=0;
    for(int i=0;i<n;++i){
        if(s[i]=='T')++cnt;
        else mx=max(mx,1+max(pref[i],suf[i]));
    }
    if(s[k]=='T')cout<<cnt+mx<<endl;
    else{
        int l=k,r=k;
        while(l>0&&a[l-1]==a[k])--l;
        while(r<n-1&&a[r+1]==a[k])++r;

        cout<<r-l+1+max(pref[l],suf[r])<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}