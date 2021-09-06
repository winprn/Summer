/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pii;

const int N=1e5+10;
int a[N],b[N];
int n,m;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("i", "r", stdin);
//    freopen("o", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    sort(a,a+n),sort(b,b+n);

    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pos;
    vector<int> ans;
    for(int i=0;i<n;++i)pos.push({a[i]+b[0],{i,0}});
    while(m--){
        auto i=pos.top();
        pos.pop();

        ans.pb(a[i.se.fi]+b[i.se.se]);
        if(i.se.se+1==n)continue;
        pos.push({a[i.se.fi]+b[i.se.se+1],{i.se.fi,i.se.se+1}});
    }

    sort(ans.begin(),ans.end());
    for(int i:ans)cout<<i<<' ';
}
