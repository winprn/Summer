#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

string s;
ll n,x,y,cnt=0;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>x>>y>>s;
    for(int i=0;i<n;++i){
        if(s[i]=='1')continue;
        while(s[i]=='0')++i;

        ++cnt;
    }
    //cout<<cnt<<endl;

    ll ans=1e18;
    for(int i=0;i<cnt;++i){
        ans=min(ans,x*i+(cnt-i)*y);
    }
    cout<<(ans==1e18?0:ans);
}