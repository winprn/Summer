/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e2+10;
map<string,string>m;
map<string,int>idx;
int cnt[N];
int n,k;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("i", "r", stdin);
//    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i){
        string s,t; cin>>s>>t;
        idx[s]=i;
        m[s]=t;
    }
    cin>>k;
    while(k--){
        string s,t; cin>>s>>t;
        if(m[s]==t)cnt[idx[s]]++;
    }

    for(int i=0;i<n;++i)cout<<cnt[i]<<' ';
}
