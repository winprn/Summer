#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int n,a,b,t;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n;
        a=-1;
        for(int d=2;d*d<=2*n;++d){
            if(2*n%d==0){
                int tmp=2*n/d;
                if((tmp-d+1)%2==0){
                    a=(tmp-d+1)/2;
                    b=d;
                    break;
                }
            }
        }

        if(a==-1)cout<<"IMPOSSIBLE"<<endl;
        else{
            cout<<n<<" = ";
            for(int i=a;i<a+b;++i){
                if(i>a)cout<<" + "<<i;
                else cout<<i;
            }
            cout<<endl;
        }
    }
}