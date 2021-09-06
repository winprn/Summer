#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int N=3e5+10;
vector<pair<pair<int,int>,int>> a;
vector<pair<int,int>> seg;
vector<int> winner;
int par[N];
int n,m;

int get(int L,int R){
    int l=0,r=(int)winner.size(),ans=-1;
    while(r>l){
        int m=l+(r-l+1)/2;
        if((winner[m]>=R)||(winner[m]>=L&&winner[m]<=R)){r=m-1,ans=m;}
        else l=m+1;
    }

    if(ans!=-1&&winner[ans]>=L&&winner[ans]<=R)return ans;
    return -1;
}

int get2(int x){
    int l=0,r=(int)seg.size(),ans=-1;
    while(r>l){
        int m=l+(r-l+1)/2;
        if(seg[m].fi<=x&&x<=seg[m].se)r=m-1,ans=m;
        else l=m+1;
    }

    if(ans!=-1&&seg[ans].fi<=x&&x<=seg[ans].se)return ans;
    return -1;
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m;
    for(int i=1;i<=n;++i)par[i]=i;
    for(int i=0;i<m;++i){
        int l,r,u;cin>>l>>r>>u;
        a.pb({{l,r},u});
        winner.pb(u);
        seg.pb({l,r});
    }
    sort(winner.begin(),winner.end()),sort(seg.begin(),seg.end());

    for(int i=0;i<m;++i){
        int l=a[i].fi.fi,r=a[i].fi.se,u=a[i].se;
        if(i==0){
            par[l]=par[r]=u;
        }else{
            int id=get(l,r);
            cout<<id<<endl;
            if(id==-1)par[l]=par[r]=u;
            else par[winner[id]]=u;
        }
    }
    for(int i=1;i<=n;++i){
        int id=get2(i);
        cout<<(par[seg[id].fi]==i?0:par[seg[id].fi])<<' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}