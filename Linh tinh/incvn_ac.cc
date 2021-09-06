#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4, mod = 5e6;
int A[maxn+1], T[51][maxn+1], n, k, F[maxn+1], ans;
struct data
{
    int val, Id;
}X[maxn+1];

bool cmt(data x, data y)
{
    return x.val < y.val || (x.val == y.val && x.Id > y.Id);
}

void Update(int x, int y, int z)
{
    while (x <= n)
    {
        T[y][x] = (T[y][x] + z) % mod;
        x += x & -x;
    }
}

int Get(int x, int y)
{
    int res = 0;
    while (x >= 0)
    {
        res = (res + T[y][x]) % mod;
        if (x == 0) return res;
        x = x & (x-1);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("i","r",stdin);
    freopen("ans","w",stdout);

    cin >> n >> k;
    for (int i=1; i<=n; i++)
    {
        cin >> X[i].val;
        X[i].Id = i;
        F[i] = 1;
    }
    sort(X+1, X+n+1, cmt);
    for (int i=1; i<=n; i++) A[X[i].Id] = i;
    for (int j=2; j<=k; j++)
        for (int i=1; i<=n; i++)
        {
            Update(A[i], j-1, F[i]);
            F[i] = Get(A[i]-1, j-1);
        }
    for (int i=1; i<=n; i++) ans = (ans + F[i]) % mod;
    cout << ans;
    return 0;
}
