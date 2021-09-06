#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=3e5+10;
string s[N];
bool bad[N];
int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i)cin>>s[i];

    unordered_map<int,int> mp,cnt;
    for(int i=0;i<n;++i){
        queue<char> q;
        int cnt1=0,cnt2=0,tmp=0,tmp2=0;
        bool ok=1;
        for(int j=0;j<(int)s[i].size();++j){
            if(s[i][j]=='(')cnt1++;
            else cnt2++;

            if(cnt2>cnt1){
                for(int k=j+1;k<(int)s[i].size();++k){
                    if(s[i][k]=='('){
                        q.push('(');
                        ++cnt1;
                    }else{
                        if(!q.empty())q.pop();
                        ++cnt2;
                    }
                }

                if(!q.empty())ok=0;
                break;
            }
        }

        if(!ok){bad[i]=1;continue;}
        mp[i]=cnt1-cnt2;
        ++cnt[mp[i]];
    }

    // for(int i=0;i<n;++i){
    //     if(bad[i])cout<<endl;
    //     else cout<<mp[i]<<' '<<cnt[mp[i]]<<endl;
    // }

    ll ans=0;
    for(int i=0;i<n;++i){
        if(mp[i]<0||bad[i])continue;
        ans+=cnt[0-mp[i]];
    }
    cout<<ans<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}