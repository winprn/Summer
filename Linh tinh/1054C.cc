#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e3+10;
int l[N],r[N],a[N];
int n;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i)cin>>l[i];
    for(int i=0;i<n;++i)cin>>r[i];
    for(int i=0;i<n;++i)a[i]=(n-l[i]-r[i]);

    bool ok=1;
    for(int i=0;i<n;++i){
        int cnt=0,cnt2=0;
        if(i==0&&l[i]!=0)ok=0;
        if(i==n-1&&r[i]!=0)ok=0;
        for(int j=0;j<i;++j)cnt+=(a[i]<a[j]);
        for(int j=i+1;j<n;++j)cnt2+=(a[i]<a[j]);
        if(cnt!=l[i]||cnt2!=r[i])ok=0;
    }
    if(!ok)cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i)cout<<a[i]<<' ';
    }
}