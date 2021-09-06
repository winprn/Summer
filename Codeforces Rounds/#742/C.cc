/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=10;
int dp[N][5];
int n,t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n;
        vector<int> dig;
        dig.push_back(0);
        while(n){
            dig.push_back(n%10);
            n/=10;
        }
        //reverse(dig.begin(),dig.end());

        dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=1;
        for(int i=1;i<=(int)dig.size();++i){
            for(int j=0;j<4;++j){
                int cnt=0,tmp=-1,tmp2=-1;
                for(int a=0;a<10;++a){
                    for(int b=0;b<10;++b){
                        int sum=a+b+(j==1||j==3);
                        if(sum%10==dig[i]){
                            if(tmp==-1)tmp=sum;
                            else tmp2=sum;
                            ++cnt;
                        }
                    }
                }
                if(j==0||j==1){
                    if(tmp>=10||tmp2>=10)dp[i+1][2]=dp[i][j]*cnt;
                    else dp[i+1][0]=dp[i][j]*cnt;
                }else if(j==2){
                    if(tmp>=10||tmp2>=10)dp[i+1][3]=dp[i][j]*cnt;
                    else dp[i+1][2]=dp[i][j]*cnt;
                }else if(j==3){
                    if(tmp>=10||tmp2>=10)dp[i+1][3]=dp[i][j]*cnt;
                    else dp[i+1][1]=dp[i][j]*cnt;
                }
            }
        }
        cout<<dp[dig.size()][0]+dp[dig.size()][1]<<endl;
    }
}
