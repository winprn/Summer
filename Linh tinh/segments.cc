#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
pair<pair<int,int>,int> a[N];
int ans[N];
int n;

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.fi.fi!=b.fi.fi)return a.fi.fi<b.fi.fi;
    if(a.fi.se!=b.fi.se)return a.fi.se>b.fi.se;

    return a.se>b.se;
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].fi.fi>>a[i].fi.se;
        a[i].se=i;
    }
    sort(a,a+n,cmp);

    stack<pair<pair<int,int>,int>> s;
    s.push(a[0]);
    for(int i=1;i<n;++i){
        auto cur=s.top();
        if(a[i].fi.fi>=cur.fi.fi&&a[i].fi.se<=cur.fi.se){
            s.push(a[i]);
            ans[a[i].se]=cur.se+1;
        }else{
            while(!s.empty()&&!(a[i].fi.fi>=s.top().fi.fi&&a[i].fi.se<=s.top().fi.se))s.pop();
            if(s.empty())s.push(a[i]);
            else{
                ans[a[i].se]=s.top().se+1;
                s.push(a[i]);
            }
        }
    }
    for(int i=0;i<n;++i)cout<<ans[i]<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}