#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

string s;
ll cnt[35][30];
ll ans=-1;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>s;
    int n=(int)s.size();
    for(int i=0;i<n;++i){
        int cur=s[i]-'a';
        for(int j=0;j<26;++j)cnt[j][cur]+=cnt[30][j];
        cnt[30][cur]++;
    }
    for(int i=0;i<26;++i)ans=max(ans,cnt[30][i]);

    for(int i=0;i<26;++i){
        for(int j=0;j<26;++j)ans=max(ans,cnt[i][j]);
    }
    cout<<ans<<endl;
}