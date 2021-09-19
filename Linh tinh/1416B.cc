/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int a[N],b[N];
int n,t;

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>t;
    while(t--){
        cin>>n;
        long long sum=0;
        for(int i=1;i<=n;++i)cin>>a[i],sum+=a[i];
        if(sum%n){cout<<-1<<endl;continue;}

        vector<pair<int,pair<int,int>>> ans;
        for(int i=2;i<=n;++i){
            if(a[i]%i){
                int need=i-(a[i]%i);
                ans.push_back({need,{1,i}});
                a[i]+=need,a[1]-=need;
            }
            ans.push_back({a[i]/i,{i,1}});
        }
        for(int i=2;i<=n;++i)ans.push_back({sum/n,{1,i}});

        cout<<ans.size()<<endl;
        for(auto i:ans)cout<<i.second.first<<' '<<i.second.second<<' '<<i.first<<endl;
    }
}
