#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int N=2e5+10;
pair<int,int> bit[2][N],b[N],c[N];
int a[N],sqr[N];
int n;

void zip(){
    vector<int> tmp(a,a+n);
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for(int i=0;i<n;++i)a[i]=lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin();
}

int add(int a,int b){
    int kq=a+b;
    if(kq>=MOD)kq-=MOD;
    return kq;
}

int mul(int a,int b){
    ll kq=1LL*a*b;
    if(kq>=MOD)kq%=MOD;

    return kq;
}

void init(){
    sqr[0]=1;
    for(int i=1;i<N;++i){
        sqr[i]=mul(sqr[i-1],2);
    }
}

pair<int,int> merge(pair<int,int> a,pair<int,int> b){
    if(b.fi>a.fi){
        a.fi=b.fi;
        a.se=b.se;
    }else if(a.fi==b.fi)a.se=add(a.se,b.se);

    return a;
}

pair<int,int> get1(int x){
    x+=5;
    pair<int,int> kq={0,0};
    for(;x>0;x-=x&(-x))kq=merge(kq,bit[0][x]);

    return kq;
}

pair<int,int> get2(int x){
    x+=5;
    pair<int,int> kq={0,0};
    for(;x<N;x+=x&(-x))kq=merge(kq,bit[1][x]);

    return kq;
}

void update1(int x,pair<int,int> val){
    x+=5;
    for(;x<N;x+=x&(-x))bit[0][x]=merge(bit[0][x],val);
}

void update2(int x,pair<int,int> val){
    x+=5;
    for(;x>0;x-=x&(-x))bit[1][x]=merge(bit[1][x],val);
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("sapso.inp", "r", stdin);
    freopen("sapso.out", "w", stdout);

    cin>>n;
    init();
    for(int i=0;i<n;++i)cin>>a[i];
    zip();
    for(int i=n-1;i>=0;--i){
        auto cur=get1(1,1,1,n,a[i]-1);
        if(cur.fi==0){
            b[i]={0,1};
            update1(1,1,1,n,1,a[i],{1,1});
        }else{
            b[i]=cur;
            cur.fi++;
            update1(a[i],cur);
        }
    }

    for(int i=n-1;i>=0;--i){
        auto cur=get2(a[i]+1);
        if(cur.fi==0){
            c[i]={0,1};
            update2(a[i],{1,1});
        }else{
            c[i]=cur;
            cur.fi++;
            update2(a[i],cur);
        }
    }

    pair<int,int> ans;
    for(int i=0;i<n;++i){
        ans=merge(ans,{b[i].fi+1+c[i].fi,mul(b[i].se,c[i].se)});
    }
    ans.se=mul(ans.se,sqr[n-ans.fi]);
    cout<<ans.fi<<' '<<ans.se<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}