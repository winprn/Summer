#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sqr(x) (x)*(x)
#define MOD 1000000007

typedef long long ll;

struct Point{
    double x,y;
    Point(){x=y=0.;}
    Point(double _x,double _y):x(_x),y(_y){}
};
Point a[105];
int b[105];
double total=0,ans=0;
int n,t;

double dist(Point a,Point b){
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

int main() {
    cout.precision(14);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>t;
    for(int i=0;i<n;++i)cin>>a[i].x>>a[i].y>>b[i];

    vector<Point>tracked;
    for(int i=0;i<n-1;++i){
        total+=dist(a[i],a[i+1]);
        double dx=1.*(a[i+1].x-a[i].x)/(b[i+1]-b[i]),dy=1.*(a[i+1].y-a[i].y)/(b[i+1]-b[i]);
        if(b[i]%t==0||i==0)tracked.pb(Point(a[i].x,a[i].y));
        for(int j=b[i]+1;j<b[i+1];++j){
            double curx=a[i].x+dx*(j-b[i]),cury=a[i].y+dy*(j-b[i]);
            if(j%t==0)tracked.pb(Point(curx,cury));
        }
    }
    tracked.pb(a[n-1]);
    for(int i=0;i<(int)tracked.size()-1;++i)ans+=dist(tracked[i],tracked[i+1]);

    cout<<((total-ans)*100)/total<<endl;
#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}


#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.";
#endif

}