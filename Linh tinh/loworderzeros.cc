#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll ans[(int)1e6+10];
ll n;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    ll cur=1;
    for(int i=1;i<=1e6;++i){
        cur*=i;
        while(cur%10==0)cur/=10;
        ans[i]=cur%10;
        cur%=1000000;
    }

    while(cin>>n,n)cout<<ans[n]<<endl;
}