#include "bits/stdc++.h"

using namespace std;

#define ms(a, x) memset(a, (x), sizeof a)

typedef long long ll;

vector<int> s, t;
ll dp[40][40][2];
ll n, m;

vector<int> get(int x) {
    vector<int> kq;
    while (x) {
        kq.push_back(x % 10);
        x /= 10;
    }

    return kq;
}

ll getOccurence(ll x, int d)
{
    ll result = 0; // Initialize result
 
    // Count appearances in numbers starting
    // from d.
    ll itr = d;
    while (itr <= x)
    {
        // When the last digit is equal to d
        if (itr%10 == d)
            result++;
 
        // When the first digit is equal to d then
        if (itr != 0 && itr/10 == d)
        {
            // increment result as well as number
            result++;
            itr++;
        }
 
        // In case of reverse of number such as 12 and 21
        else if (itr/10 == d-1)
            itr = itr + (10 - d);
        else
            itr = itr+10;
    }
    return result;
}

int main() {
    freopen("i", "r", stdin);

    while (cin >> n >> m, n >= 0) {
        cout << getOccurence(n - 1, 0) << endl;
        cout << getOccurence(m, 0) << endl;
    }
}