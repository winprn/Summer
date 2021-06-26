#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll n,m,h,w;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m;
    for(int i=1;i<n/2+2;++i){
        int j=n/2+2-i;
        if(1LL*i*j==m-4+2*i+2*j){
            h=max(i,j);
            w=min(i,j);
            break;
        }
    }
    cout<<h<<' '<<w<<endl;
}