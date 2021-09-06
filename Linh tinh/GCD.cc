/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int MX=6e6+10;
const int N=1e5+10;
int a[N],pr[MX];
int n;

void sieve(){
    for(int i=2;i<MX;++i)pr[i]=i;
    for(int i=2;i*i<MX;++i){
        if(pr[i]==i)for(int j=i*i;j<MX;j+=i)pr[j]=i;
    }
}

vector<int> get(int x){
    vector<int> kq;
    while(x!=1){
        kq.push_back(pr[x]);
        x/=pr[x];
    }

    return kq;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("i", "r", stdin);
//    freopen("o", "w", stdout);

    sieve();
    cin>>n;
    int gcd=0;
    for(int i=0;i<n;++i){
        cin>>a[i],gcd=__gcd(gcd,a[i]);
    }
    for(int i=0;i<n;++i)a[i]/=gcd;

    map<int,int> cnt;
    for(int i=0;i<n;++i){
        set<int> cur;
        auto tmp=get(a[i]);
        for(int j:tmp)cur.insert(j);

        for(auto j:cur)cnt[j]++;
    }

    int ans=1e9;
    for(auto i:cnt){
        if((n-i.second)<ans||ans==-1)ans=n-i.second;
    }
    cout<<(ans==1e9?-1:ans);
}
