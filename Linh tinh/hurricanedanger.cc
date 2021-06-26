#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sqr(x) (x)*(x)
#define MOD 1000000007

typedef long long ll;
typedef double ld;

struct Line{
    ld a,b,c;
};

struct Point{
    ld x,y;
    Point(ld _x,ld _y):x(_x),y(_y){}
};

struct Vec{
    ld x,y;
    Vec(ld _x,ld _y):x(_x),y(_y){}
};
Vec toVec(Point a, Point b){
    return Vec(b.x-a.x,b.y-a.y);
}
Vec scale(const Vec &v,double s){
    return Vec(v.x*s,v.y*s);
}
Point translate(const Point &p,const Vec &v){
    return Point(p.x+v.x,p.y+v.y);
}
ld dot(Vec a,Vec b){
    return a.x*b.x+a.y*b.y;
}
ld norm(Vec v){
    return sqr(v.x)+sqr(v.y);
}
ld get(Point p,Point a,Point b){
    Vec ap=toVec(a,p),ab=toVec(a,b);
    ld u=dot(ap,ab)/norm(ab);
    Point c=translate(a,scale(ab,u));

    return sqrt(sqr(p.x-c.x)+sqr(p.y-c.y));
}
const ld EPS=1e-6;
const int N=5e2+10;
string name[N];
ld dist[N];
int t,n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        memset(dist,0,sizeof dist);
        ld x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cin>>n;
        Point a=Point(x1,y1),b=Point(x2,y2);
        ld mn=1e18;
        for(int i=0;i<n;++i){
            cin>>name[i];
            ld x,y;cin>>x>>y;
            Point cur=Point(x,y);
            dist[i]=get(cur,a,b);
            mn=min(mn,dist[i]);
        }

        vector<string>ans;
        for(int i=0;i<n;++i)if(fabs(dist[i]-mn)<=EPS)ans.pb(name[i]);
        for(auto i:ans)cout<<i<<' ';
        cout<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}