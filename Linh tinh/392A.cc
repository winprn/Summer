#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

char a[105][105];
bool mark[105][105];
int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>a[i][j];

    bool ok=1,ok2=1;
    for(int i=0;i<n;++i){
        ok=0;
        for(int j=0;j<n;++j){
            if(a[i][j]!='E')ok=1;
        }

        if(!ok)break;
    }
    for(int j=0;j<n;++j){
        ok2=0;
        for(int i=0;i<n;++i){
            if(a[i][j]!='E')ok2=1;
        }

        if(!ok2)break;
    }

    if(!ok&&!ok2)cout<<"-1";
    else{
        if(ok){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(a[i][j]!='E'){
                        cout<<i+1<<' '<<j+1<<endl;
                        break;
                    }
                }
            }
        }else{
            for(int j=0;j<n;++j){
                for(int i=0;i<n;++i){
                    if(a[i][j]!='E'){
                        cout<<i+1<<' '<<j+1<<endl;
                        break;
                    }
                }
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}