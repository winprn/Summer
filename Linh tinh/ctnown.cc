/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=4e2;
vector<int> primes;
unsigned long long dp[N][80];
bitset<N> pr;
int n,t;

void sieve(){
    pr.set();
    pr[0]=pr[1]=0;
    primes.push_back(-1);
    for(int i=2;i<=370;++i){
        if(pr[i]){
            primes.push_back(i);
            for(int j=i*i;j<=370;j+=i)pr[j]=0;
        }
    }
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}

unsigned long long lcm(unsigned long long a,unsigned long long b){
    return a*b/gcd(a,b);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    //for(int i:primes)cout<<i<<' ';
    dp[1][0]=1;
    for(int i=0;i<=(int)primes.size();++i)dp[0][i]=1;
    for(int i=1;i<=350;++i){
        for(int j=1;;++j){
            if(primes[j]>i)break;
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            int k=primes[j];
            while(i-k>=0){
                dp[i][j]=max(dp[i][j],dp[i-k][j-1]*k);
                k*=primes[j];
            }
        }
    }

    cin>>t;
    while(t--){
        cin>>n;
        cout<<*max_element(dp[n],dp[n]+70)<<endl;
    }
}
