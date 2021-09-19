/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

const int MOD=998244353;
const int N=5e5+10;
int fact[N];
int n,k;

int nhan(int a,int b){
    return (a*1LL*b)%MOD;
}

int mu(int x,int y){
    int kq=1;
    while(y){
        if(y&1)kq=nhan(kq,x);
        x=nhan(x,x);

        y/=2;
    }

    return kq;
}

int inv(int a){
    return mu(a,MOD-2);
}

int chia(int a,int b){
    return nhan(a,inv(b));
}

int nCk(int n,int k){
    return chia(fact[n],nhan(fact[n-k],fact[k]))%MOD;
}

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>n>>k;
    fact[0]=1;
    for(int i=1;i<=n;++i)fact[i]=(1LL*i*fact[i-1])%MOD;

    int ans=0;
    for(int i=1;i<=n;++i){
        int div=n/i;
        if(div-1<k-1)continue;
        if(k-1==0){++ans;continue;}
        //cout<<div-1<<' '<<k-1<<' '<<nCk(div-1,k-1)<<endl;
        ans=(ans+nCk(div-1,k-1))%MOD;
    }
    cout<<ans;
}
