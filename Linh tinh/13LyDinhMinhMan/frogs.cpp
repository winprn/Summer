#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

const int N=1e6+10;
vector<int> cur;
int a[N],b[N],ans[N];
bool mark[N];
int n;

int main() {
    freopen("frogs.inp", "r", stdin);
    freopen("frogs.out", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    for(int i=0;i<n;++i)scanf("%d",&b[i]);
    cur.pb(1e9);

    for(int i=n-1;i>=0;--i){
        while(cur.back()<=a[i])cur.pop_back();
        ans[i]=cur[max(0,(int)cur.size()-b[i])];
        cur.pb(a[i]);
    }
    for(int i=0;i<n;++i){
        if(ans[i]==1e9)printf("-1 ");
        else printf("%d ",ans[i]);
    }
    printf("\n");

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}