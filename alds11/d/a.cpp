#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi r(n);
    rep(i, n) cin >> r[i];

    int maxv = -2000000000;
    int minv = r[0];

    for(int i=1; i<n; i++) {
        maxv = max(maxv, r[i]-minv);
        minv = min(minv, r[i]);
    }

    cout << maxv << endl;

    return 0;
}
