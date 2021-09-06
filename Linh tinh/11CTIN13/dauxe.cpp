#include<bits/stdc++.h>
#include<ext/numeric>
#define fastIO                  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, j, k, in)		for (int i = (j); i < (k); i += (in))
#define FORW(i, j, k, in)		for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)		for (int i = (j); i >= (k); i -= (in))
#define RFORW(i, j, k, in)		for (int i = (j); i > (k); i -= (in))
#define sz(arr)                 ((int)(arr).size())
#define pb                      push_back
#define fi						first
#define se						second

using namespace std;
using namespace __gnu_cxx;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<pii,int> piii;
typedef vector<pii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

const int inf=1e9+7;
const float PI=acos(-1);
const ll linf=1e18l+7;
const int N=128;
char a[N];
int n,l,c,sl,res;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("dauxe.inp","r",stdin);
        freopen("dauxe.out","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n>>l;
    int t=0;
    while(cin>>a[++sl]){
        //cin>>a[i];
        if(a[sl]=='X') t=0;
        else ++t;
        if(t==l){
            ++c;
            t=0;
        }
    }
    t=0;
    FORW(i,1,sl,1){
        if(a[i]=='X') t=0;
        else ++t;
        if(t==l&&res<n){
            ++res;
            t=0;
        }

    }
    cout<<c-res<<"\n"<<res;
}
