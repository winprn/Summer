#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

vector<int> kq[25],ans;
int n,sum;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>sum>>n;
    for(int i=1;i<=n;++i){
        for(int bit=0;bit<20;++bit){
            if(i&(1<<bit)){
                kq[bit].pb(i);
                break;
            }
        }
    }

    for(int bit=19;bit>=0;--bit){
        for(auto i:kq[bit]){
            if(sum>=(1<<bit)){
                ans.pb(i);
                sum-=(1<<bit);
            }else break;
        }
    }

    if(sum!=0)cout<<"-1";
    else{
        cout<<ans.size()<<endl;
        for(int i:ans)cout<<i<<' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}