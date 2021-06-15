#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll f[10]={9,189,2889,38889,488889,5888889,68888889,788888889,8888888889};
ll n, t;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    if(n<10)cout<<n<<endl;
    else{
        ll cur=10;
        int idx=-1;
        for(int i=1;i<=8;++i){
            if(cur*10>n){idx=i-1;break;}
            cur*=10;
        }
        if(idx==-1)idx=8;

        //cout<<cur<<' '<<idx<<endl;
        cout<<f[idx]+(n-cur+1)*(idx+2)<<endl;
    }
}