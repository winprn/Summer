#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int n,m,s;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m>>s;
    if(n*m/__gcd(n,m)<=s)cout<<"yes";
    else cout<<"no";
}