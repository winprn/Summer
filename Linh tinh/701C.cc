#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

string s;
int cnt[105],ans[(int)1e5+10];
int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>s;
    for(int i=1;i<=n;++i)ans[i]=1e9;

    int total=0,j=0;
    for(int i=0;i<n;++i){
        if(cnt[s[i]-'A']==0)++total;
        cnt[s[i]-'A']++;
        while(j<i&&cnt[s[j]-'A']>1)cnt[s[j++]-'A']--;

        ans[total]=min(ans[total],i-j+1);
    }
    cout<<ans[total];

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif

}