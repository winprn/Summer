#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int n,m,t;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n>>m;
        int tmp=(n-1)/__gcd(n-1,m-1)*(m-1);

        cout<<tmp+1-(tmp/(n-1)-1)*((tmp/(m-1)-1))/2<<endl;
    }
}