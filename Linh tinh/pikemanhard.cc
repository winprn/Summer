/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
const int N=1e6+10;
long long t[N],idx[N],cnt[N];
long long n,a,b,c,T,s=-1,ss=-1;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>T>>a>>b>>c>>t[0];
    memset(idx,-1,sizeof(idx));
    for(int i=0;;++i){
        if(i)t[i]=(a*t[i-1]+b)%c+1;
        if(idx[t[i]]==-1)idx[t[i]]=i;
        else{
            s=t[i];
            ss=i;
            break;
        }
    }

    long long tmp=n,m=ss-idx[s];
    for(int i=0;t[i]!=s&&tmp>0;++i,--tmp){
        cnt[t[i]]++;
    }
    for(int i=0,j=s;i<m;++i,j=(a*j+b)%c+1){
        cnt[j]+=tmp/m;
        if(i<tmp%m)++cnt[j];
    }

//    cout<<s<<' '<<m<<endl;
//    for(int i=0;i<=c;++i)cout<<i<<' '<<idx[i]<<' '<<cnt[i]<<endl;

    long long ans=0,ans2=0,used=0;
    for(int i=1;i<=c;++i){
        if(!cnt[i])continue;
        if(T<i)break;
        long long take=min(cnt[i],T/i);
        tmp=take%MOD;
        ans+=take;
        T-=i*take;
        ans2=(ans2+((tmp*(used%MOD))%MOD))%MOD;

        if(tmp&1){
            ans2=(ans2+(((((tmp+1)/2*tmp)%MOD)*i)%MOD))%MOD;
            //tm = (tm + ((((sM / 2 * (sM + 1)) % MOD) * j) % MOD)) % MOD;
        }else{
            ans2=(ans2+((((tmp/2*(tmp+1))%MOD)*i)%MOD))%MOD;
            //tm = (tm + (((((sM + 1) / 2 * sM) % MOD) * j) % MOD)) % MOD;
        }
        used+=i*take;
    }
    cout<<ans<<' '<<ans2%MOD;
}
