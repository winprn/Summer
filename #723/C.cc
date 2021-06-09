#include "bits/stdc++.h"

using namespace std;

long long ans, h;
int n;

int main() {
    freopen("i", "r", stdin);

    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        s += x;
        pq.push(x);

        while (s < 0) {
            s -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << endl;
}