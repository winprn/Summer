#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

typedef long long ll;

int pw[30];
int n,ans=0;

int cong(int a,int b){
    a+=b;
    if(a>=MOD)a-=MOD;
    else if(a<0)a+=MOD;

    return a;
}

int nhan(int a, int b){
    return 1LL*a*b%MOD; 
}

int f(string s){
    int n=(int)s.size(),kq=0;
    for(int i=0;i<n;++i){
        int cur=s[n-i-1]-'0';
        kq=cong(kq,nhan(cur,pw[2*i]));
        kq=cong(kq,nhan(cur,pw[2*i+1]));
    }

    return kq;
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    pw[0]=1;
    for(int i=1;i<=25;++i)pw[i]=nhan(pw[i-1],10);
    cin>>n;
    for(int i=0;i<n;++i){
        string x; cin>>x;
        ans=cong(ans,nhan(n,f(x)));
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}