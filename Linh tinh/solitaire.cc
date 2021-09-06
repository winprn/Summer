/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

char a[15][15];
pair<int,int> ans={1e9,0};
int cnt=0,t;

void dfs(int cur,int moves){
    if(cur<ans.first){
        ans={cur,moves};
    }else if(cur==ans.first)ans={cur,min(ans.second,moves)};
    if(cur==1)return ;

    for(int i=1;i<=5;++i){
        for(int j=1;j<=9;++j){
            if(a[i][j]=='o'){
                if(a[i-1][j]=='o'&&i>2&&a[i-2][j]=='.'){
                    swap(a[i-1][j],a[i-2][j]);
                    a[i][j]='.';
                    dfs(cur-1,moves+1);
                    a[i][j]='o';
                    swap(a[i-1][j],a[i-2][j]);
                }
                if(a[i+1][j]=='o'&&i<=3&&a[i+2][j]=='.'){
                    swap(a[i+1][j],a[i+2][j]);
                    a[i][j]='.';
                    dfs(cur-1,moves+1);
                    a[i][j]='o';
                    swap(a[i+1][j],a[i+2][j]);
                }
                if(a[i][j-1]=='o'&&j>2&&a[i][j-2]=='.'){
                    swap(a[i][j-1],a[i][j-2]);
                    a[i][j]='.';
                    dfs(cur-1,moves+1);
                    a[i][j]='o';
                    swap(a[i][j-1],a[i][j-2]);
                }
                if(a[i][j+1]=='o'&&j<=7&&a[i][j+2]=='.'){
                    swap(a[i][j+1],a[i][j+2]);
                    a[i][j]='.';
                    dfs(cur-1,moves+1);
                    a[i][j]='o';
                    swap(a[i][j+1],a[i][j+2]);
                }
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cnt=0;
        for(int i=1;i<=5;++i)for(int j=1;j<=9;++j)cin>>a[i][j],cnt+=(a[i][j]=='o');
//        for(int i=1;i<=5;++i){
//            for(int j=1;j<=9;++j)cout<<a[i][j];
//            cout<<endl;
//        }

        ans={1e9,0};
        dfs(cnt,0);
        cout<<ans.first<<' '<<ans.second<<endl;
    }
}
