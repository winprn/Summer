#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
pair<pair<int,int>,int> a[N];
int mark[N];
int n,t;

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.fi.se!=b.fi.se)return a.fi.se<b.fi.se;
    if(a.fi.fi!=b.fi.fi)return a.fi.fi<b.fi.fi;
    return a.se<b.se;
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>a[i].fi.fi>>a[i].fi.se;
            a[i].se=i;
        }
        sort(a,a+n,cmp);
        //for(int i=0;i<n;++i)cout<<a[i].fi<<' '<<a[i].se<<endl;

        int mn=a[n-1].fi.fi;
        bool ok=0;
        for(int i=n-2;i>=0;--i){
            if(a[i].fi.se<mn){
                memset(mark,0,sizeof mark);
                ok=1;
                for(int j=0;j<=i;++j)mark[a[j].se]=1;
                for(int j=0;j<n;++j)cout<<1+mark[j]<<' ';

                break;
            }
            mn=min(mn,a[i].fi.fi);
        }
        if(!ok)cout<<"-1";
        cout<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}