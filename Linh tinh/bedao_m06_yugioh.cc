/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
bitset<N> pr;
vector<int> primes;
long long a[N],p[N],prime[N];
int n,m;

void sieve(int x){
    pr.set();
    pr[0]=pr[1]=0;
    for(int i=2;i<=x;++i){
        if(pr[i]) primes.push_back(i);
        for(int j=0;j<primes.size()&&i*primes[j]<=x;j++){
            pr[i*primes[j]]=0;
            if(i%primes[j]==0) break;
        }
    }
}

int get(int x){
    if(x<0||x>m)return 0;
    return pr[x];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m;
    sieve(m);
    for(int i=1;i<=n;++i)cin>>a[i],p[i]=(i?p[i-1]:0)+get(a[i]);

    long long ans=(n+1)/2;
    for(int i=p[n];i<=n;++i){
        ans=min(ans,p[n]+p[i-p[n]]-p[i]);
    }
    cout<<ans;
}
