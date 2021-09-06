/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

#define sqr(x) (x)*(x)

const int N=40;
vector<int> ok[N];
double x[N],y[N];
int n,l,w,r;

bool check(int i,int j){
    return(sqr(x[i]-x[j])+sqr(y[i]-y[j])<=sqr(r));
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>l>>w>>n>>r;
    x[0]=(-l/2.),y[0]=0;
    x[1]=(l/2.),y[1]=0;
    x[2]=0,y[2]=(-w/2.0);
    x[3]=0,y[3]=(w/2.0);
    for(int i=4;i<n+4;++i){
        cin>>x[i]>>y[i];
        for(int j=0;j<4;++j){
            if(check(i,j))ok[j].push_back(i);
        }
    }

    if(ok[0].empty()||ok[1].empty()||ok[2].empty()||ok[3].empty())cout<<"Impossible";
    else{
        int ans=5,cur=0;
        for(int i:ok[0]){
            cur=1;
            for(int j:ok[1]){
                cur+=(j!=i);
                for(int k:ok[2]){
                    cur+=(k!=i&&k!=j);
                    for(int l:ok[3]){
                        cur+=(l!=i&&l!=j&&l!=k);
                        ans=min(ans,cur);
                        cur-=(l!=i&&l!=j&&l!=k);
                    }
                    cur-=(k!=i&&k!=j);
                }
                cur-=(j!=i);
            }
        }
        cout<<ans;
    }
}
