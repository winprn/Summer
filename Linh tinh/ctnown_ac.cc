#include <iostream>
#include <cstdio>
using namespace std;


const int COSO = 10000;

struct BigInt {
    int a[20];
    void assign(int x) {
        a[0] = x;
        for(int i=1;i<20;++i)
            a[i] = 0;
    }
    void viet() {
        for(int i=20-1;i>=0;--i)
            if(a[i] > 0) {
                printf("%d",a[i]);
                for(int j=i-1;j>=0;--j)
                    printf("%04d",a[j]);
                break;
            }
    }
    BigInt opMul(int x){
        BigInt b;
        int nho = 0;
        for(int i=0;i<20;++i) {
            nho += a[i] * x;
            b.a[i] = nho % COSO;
            nho /= COSO;
        }
        return b;
    }
    int opCmp(BigInt b) {
        for(int i=20-1;i>=0;--i) {
            if(a[i] < b.a[i]) return -1;
            if(a[i] > b.a[i]) return 1;
        }
        return 0;
    }
};

const int MAXN = 355;

BigInt F[MAXN][300];

int prime[1000];

int main() {
    freopen("i","r",stdin);
    freopen("ans","w",stdout);

    int nprime = 0;
    for(int i=2;i<300;++i) {
        bool isprime = true;
        for(int j=2;j*j<=i;++j)
            if(i % j == 0) {
                isprime = false;
                break;
            }
        if(isprime)
            prime[nprime++] = i;
    }

    for(int i=0;i<MAXN;++i) {
        if(i < 2) F[i][0].assign(1);
        else {
            int z = 2;
            while(2 * z <= i) z *= 2;
            F[i][0].assign(z);
        }
    }

    for(int p=1;p<nprime;++p) {
        for(int i=0;i<MAXN;++i) {
            F[i][p] = F[i][p-1];
            int z = prime[p];
            while(z <= i) {
                BigInt tmp = F[i-z][p-1] .opMul( z );
                if(F[i][p] .opCmp( tmp ) < 0) {
                    F[i][p] = tmp;
                }
                z *= prime[p];
            }
        }
    }

    int ntest, n;
    scanf("%d",&ntest);
    for(int test=0;test<ntest;++test) {
        scanf("%d",&n);
        F[n][nprime-1].viet();
        printf("\n");
    }
    return 0;
}
