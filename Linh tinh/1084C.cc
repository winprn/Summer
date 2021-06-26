#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

string s,t;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>s;
    int n=(int)s.size();
    for(int i=0;i<n;++i){
        if(s[i]!='a'&&s[i]!='b')continue;
        t.push_back(s[i]);
    }
    //cout<<s<<endl;

    n=(int)t.size();
    vector<int>all;
    for(int i=0;i<n;++i){
        if(t[i]=='b')continue;
        int len=0;
        while(t[i]=='a')++len,++i;
        all.push_back(len);
    }

    ll ans=1;
    for(auto i:all){
        ans*=(i+1);
        ans%=MOD;
    }
    cout<<ans-1;
}