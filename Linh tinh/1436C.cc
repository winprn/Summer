#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int fact[1005],inv[1005];
int n,x,pos,small,big,bigger,smaller,left,res;

void bs(){
    int l=0,r=n;
    while(r>l){
        int m=(r+l)/2;
        if(pos>=m){
            l=m+1;
            if(pos!=m)++small;
        }else{
            r=m;
            ++big;
        }
    }
}

int fexp(int a,int b){
    ll kq=1;
    while(b){
        if(b&1)kq=1LL*kq*a%MOD;
        a=1LL*a*a%MOD;
        b>>=1;
    }
    return kq;
}

int C(int n,int k){
    if(k>n)return 0;
    int kq=1LL*fact[n]*inv[k]%MOD;
    kq=1LL*kq*inv[n-k]%MOD;
    return kq;
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>x>>pos;
    fact[0]=inv[0]=1;
    for(int i=1;i<=n;++i){
        fact[i]=1LL*fact[i-1]*i%MOD;
        inv[i]=fexp(fact[i],MOD-2);
    }
    bs();
    int left=n-big-small-1;
    int bigger=n-x,smaller=x-1;
    int cnt=C(bigger,big),cnt2=C(smaller,small);
    //cout<<big<<' '<<small<<' '<<bigger<<' '<<smaller<<' '<<cnt2<<' '<<cnt<<endl;

    cnt=1LL*cnt*fact[big]%MOD,cnt2=1LL*cnt2*fact[small]%MOD;
    int ans=1LL*cnt*cnt2%MOD;
    ans=1LL*ans*fact[left]%MOD;
    cout<<ans;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}