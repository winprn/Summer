/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int p[N];
int n,k;

int get(int l,int r){
    l=(l+n)%n,r=(r+n)%n;
    return p[r]-p[l-1]+(l>r?p[n-1]:0);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>k;
    long long tot=0;
    for(int i=0;i<k;++i){
        int x; cin>>x,--x;
        p[x]++;
        tot+=min(x,n-x);
    }

    vector<int> ans;
    long long mx=tot;
    ans.push_back(1);
    for(int i=1;i<n;++i)p[i]+=p[i-1];
    for(int i=1;i<n;++i){
        tot+=get(i-n/2,i-1)-get(i,i+n/2-1);
        if(tot==mx)ans.push_back(i+1);
        else if(tot<mx){
            mx=tot;
            ans.clear();
            ans.push_back(i+1);
        }
    }

    cout<<mx<<endl<<ans.size()<<endl;
    for(int i:ans)cout<<i<<' ';
}
