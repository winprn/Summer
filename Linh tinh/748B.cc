#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

string s,t;
vector<int> ans;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>s>>t;
    unordered_map<char,char> mp;
    for(int i=0;i<26;++i)mp[(char)('a'+i)]='.';
    int n=(int)s.size();
    bool ok=1;
    for(int i=0;i<n;++i){
        if(s[i]==t[i]){
            if(mp[s[i]]=='.'&&mp[t[i]]=='.')mp[s[i]]=mp[t[i]]=s[i];
            if(mp[s[i]]!=t[i]||mp[t[i]]!=s[i]){ok=0;break;}
            mp[s[i]]=mp[t[i]]=s[i];
            continue;
        }
        if(mp[s[i]]=='.'){
            if(mp[t[i]]=='.'){
                mp[s[i]]=t[i],mp[t[i]]=s[i];
                ans.pb(i);
            }else if(mp[t[i]]!=s[i]){ok=0;break;}
        }else if(mp[s[i]]!=t[i]){ok=0;break;}
    }

    if(!ok)cout<<"-1";
    else{
        cout<<ans.size()<<endl;
        for(auto i:ans)cout<<s[i]<<' '<<t[i]<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}