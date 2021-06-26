#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N = 1e5+10;
int a[N],p[12][N],cur[12];
int n,ans=0;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        
        if(i){
            for(int j=1;j<=10;++j)p[j][i]=p[j][i-1];
            p[a[i]][i]=p[a[i]][i-1]+1;
        }else ++p[a[i]][i];
    }

    for(int i=0;i<n;++i){
        int mx=-1,idx;
        for(int j=1;j<=10;++j)cur[j]=p[j][i];
        for(int j=1;j<=10;++j){
            if(cur[j]>mx&&cur[j]!=0)mx=cur[j],idx=j;
        }

        bool ok=1;
        cur[idx]--;
        --mx;
        for(int j=1;j<=10;++j){
            if(cur[j]==0)continue;
            if(cur[j]!=mx&&mx!=0){ok=0;break;}
        }
        cur[idx]++;

        if(ok)ans=i;
        else{
            mx=1e9,ok=1;
            for(int j=1;j<=10;++j){
                if(cur[j]<mx&&cur[j]!=0)mx=cur[j],idx=j;
            }

            int tmp=*max_element(cur+1,cur+11);
            cur[idx]--;
            --mx;
            for(int j=1;j<=10;++j){
                if(cur[j]==0)continue;
                if(cur[j]!=mx&&mx!=0){ok=0;break;}
                if(cur[j]!=tmp){ok=0;break;}
            }
            cur[idx]++;

            if(ok)ans=i;
        }
    }
    cout<<ans+1<<endl;
}