#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=2e5+10;
int st[8*N];
int n,m,cur=-1;

void update(int id,int l,int r,int i,int val){
    if(i<l||i>r)return;
    if(l==r){
        st[id]=val;
        return;
    }

    int m=(l+r)/2;
    update(id*2,l,m,i,val);
    update(id*2+1,m+1,r,i,val);
    st[id]=max(st[id*2],st[id*2+1]);
}

int get(int v,int tl,int tr,int l,int r,int val){
    if(tl>r||tr<l)return -1;
    if(l<=tl&&r>=tr){
        if(st[v]<=val)return -1;
        while(tl!=tr){
            int m=tl+(tr-tl)/2;
            if(st[2*v]>val){
                v=2*v;
                tr=m;
            }else{
                v=2*v+1;
                tl=m+1;
            }
        }
        cur=v;
        return tl;
    }

    int mid=(tl+tr)/2;
    int ans=get(2*v,tl,mid,l,r,val);
    if(ans!=-1)return ans;
    return get(2*v+1,mid+1,tr,l,r,val);
}

int main() {
    cout.precision(10);
    cout<<fixed;
    // freopen("i", "r", stdin);
    // freopen("o", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        int x; cin>>x;
        update(1,1,n,i+1,x);
    }

    for(int i=0;i<m;++i){
        int x; cin>>x;
        int tmp=get(1,1,n,1,n,x-1);
        if(tmp==-1)cout<<0<<' ';
        else{
            cout<<tmp<<' ';
            update(1,1,n,tmp,st[cur]-x);
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}