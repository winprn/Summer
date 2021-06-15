#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int a[(1<<20)], dp[(1<<20)];
int n;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];

    for(int i=0;i<n;++i)dp[i]=a[i];
    for(int i=0;i<n;++i){
        for(int mask=0; mask<(1 << n);++mask){
            if(mask&(1<<i))dp[mask]+=dp[mask^(1<<i)];
        }
    }

    for(int i=0;i<(1<<n);++i)cout<<dp[i]<<' ';
    cout<<endl;
}