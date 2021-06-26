#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

struct Point{
    int x,y;
};
const int N=2e4+10;
Point a[N];
int n;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    while(cin>>n,n){
        for(int i=0;i<n;++i)cin>>a[i].x>>a[i].y;

        Point mid=a[n/2];
        int ans1=0,ans2=0;
        for(int i=0;i<n;++i){
            if(i==n/2)continue;
            if((a[i].x>mid.x&&a[i].y>mid.y)||(a[i].x<mid.x&&a[i].y<mid.y))++ans1;
            if((a[i].x<mid.x&&a[i].y>mid.y)||(a[i].x>mid.x&&a[i].y<mid.y))++ans2;
        }
        cout<<ans1<<' '<<ans2<<endl;
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}