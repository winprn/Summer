#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

char n[1010];
int f[10], ans[2010];
int len;

bool ok(int x){
    char tmp[1010];
    int len2=0,cur=0;
    for(int i=0;i<len;++i){
        tmp[len2++]=(cur*10+n[i])/x;
        cur=(cur*10+n[i])%x;
    }
    if(!cur){
        for(int i=0;i<len2;++i)n[i]=tmp[i];
        len=len2;
        return 1;
    }

    return 0;
}

int get(int x){
    int res=0;
    while(ok(x))++res;
    return res;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    while(fgets(n,1002,stdin)!=NULL){
        if(n[0]=='-')break;
        len=strlen(n)-1;
        for(int i=0;i<len;++i)n[i]-='0';
        bool iszero=1;
        for(int i=0;i<len&&iszero;++i)if(n[i])iszero=0;
        if(iszero){cout<<"10"<<endl;continue;}
        iszero=1;
        for(int i=0;i<len-1&&iszero;++i)if(n[i])iszero=0;
        if(iszero){cout<<1<<(char)(n[len-1]+'0')<<endl;continue;}
    
        f[2]=get(2);
        f[3]=get(3);
        f[5]=get(5);
        f[7]=get(7);
        //cout<<f[2]<<' '<<f[3]<<' '<<f[5]<<' '<<f[7]<<endl;
        iszero=1;
        for(int i=0;i<len-1&&iszero;++i)if(n[i])iszero=0;
        if(!iszero||n[len-1]!=1){
            cout<<"There is no such number."<<endl;
            continue;
        }

        int cnt=0;
        while(f[3]>1){ans[cnt++]=9,f[3]-=2;}
        while(f[2]>2){ans[cnt++]=8,f[2]-=3;}
        while(f[7]){ans[cnt++]=7,f[7]--;}
        while(f[2]&&f[3]){ans[cnt++]=6,f[2]--,f[3]--;}
        while(f[5]){ans[cnt++]=5,f[5]--;}
        while(f[2]>1){ans[cnt++]=4,f[2]-=2;};
        while(f[3]){ans[cnt++]=3,f[3]--;}
        while(f[2]){ans[cnt++]=2,f[2]--;}
    
        for(int i=cnt-1;i>=0;--i)cout<<ans[i];
        cout<<endl;
    }
}