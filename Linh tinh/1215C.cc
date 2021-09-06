#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

string s,t;
vector<int> idx[2];
int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>s>>t;
    for(int i=0;i<n;++i){
        if(s[i]==t[i])continue;
        if(s[i]=='a')idx[0].pb(i);
        else idx[1].pb(i);
    }

    if((int)idx[0].size()%2!=(int)idx[1].size()%2)cout<<"-1"<<endl;
    else{
        vector<pair<int,int>> ans;
        for(int i=0;i<(int)idx[0].size()-1;i+=2)ans.pb({idx[0][i],idx[0][i+1]});
        for(int i=0;i<(int)idx[1].size()-1;i+=2)ans.pb({idx[1][i],idx[1][i+1]});

        if((int)idx[0].size()&1){
            int i=idx[0].back(),j=idx[1].back();
            ans.pb({i,i});
            ans.pb({i,j});
        }

        cout<<ans.size()<<endl;
        for(auto i:ans)cout<<i.fi+1<<' '<<i.se+1<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}