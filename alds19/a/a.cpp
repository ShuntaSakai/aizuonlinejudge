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

int parent(int i) { return i/2; }
int left(int i) { return 2*i; }
int right(int i) { return 2*i+1; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, A[MAX+1];
    cin >> H;
    rep(i, H) cin >> A[i+1];

    rep(i, H) {
        cout << "node " << i+1 << ": key = " << A[i+1] << ", ";
        if(parent(i+1)>=1) cout << "parent key = " << A[parent(i+1)] << ", ";
        if(left(i+1)<=H) cout << "left key = " << A[left(i+1)] << ", ";
        if(right(i+1)<=H) cout << "right key = " << A[right(i+1)]  << ", ";
        cout << endl;
    }

    return 0;
}
