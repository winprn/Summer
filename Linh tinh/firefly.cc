#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

vector<int> a,b;
int n,h;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>h;
    for(int i=0;i<n;++i){
        int x;cin>>x;
        if(i&1)b.pb(x);
        else a.pb(x);
    }
    sort(a.begin(),a.end()),sort(b.begin(),b.end());

    int mn=1e9,num=0;
    for(int lev=1;lev<=h;++lev){
        auto it=lower_bound(a.begin(),a.end(),lev)-a.begin();
        auto it2=upper_bound(b.begin(),b.end(),h-lev)-b.begin();
        //cout<<lev<<' '<<it<<' '<<it2<<endl;
        if((int)a.size()-it+(int)b.size()-it2<mn){
            mn=a.size()-it+b.size()-it2;
            num=1;
        }else if((int)a.size()-it+(int)b.size()-it2==mn)++num;
    }
    cout<<mn<<' '<<num<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}