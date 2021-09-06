#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=2e5+10;
struct data{
    ll sum,pref,suf,ans;
}st[8*N];
int a[N];
int n,m;

data combine(data l,data r){
    data kq;
    kq.sum=l.sum+r.sum;
    kq.pref=max(l.pref,l.sum+r.pref);
    kq.suf=max(r.suf,r.sum+l.suf);
    kq.ans=max({l.ans,r.ans,l.suf+r.pref});
    return kq;
}

data make_data(int val){
    data kq;
    kq.sum=val;
    kq.pref=kq.suf=kq.ans=max(0,val);
    return kq;
}

void build(int id,int l,int r){
    if(l==r){
        st[id]=make_data(a[l]);
    }else{
        int m=(l+r)/2;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=combine(st[id*2],st[id*2+1]);
    }
}

void update(int id,int l,int r,int i,int v){
    if(l==r)st[id]=make_data(v);
    else{
        int m=(l+r)/2;
        if(i<=m)update(id*2,l,m,i,v);
        else update(id*2+1,m+1,r,i,v);
        st[id]=combine(st[id*2],st[id*2+1]);
    }
}

data get(int id,int tl,int tr,int l,int r){
    if(l>r)return make_data(0);
    if(l==tl&&r==tr)return st[id];
    int m=(tl+tr)/2;
    return combine(get(id*2,tl,m,l,min(r,m)),get(id*2+1,m+1,tr,max(l,m+1),r));
}

int main() {
    cout.precision(10);
    cout<<fixed;
    // freopen("i", "r", stdin);
    // freopen("o", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>a[i+1];
    build(1,1,n);

    for(int i=0;i<m;++i){
        int id,v; cin>>id>>v;
        update(1,1,n,id,v);
        cout<<get(1,1,n,1,n).ans<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}