#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <utility>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

int selectionSort(int n, vi &A) {
    int minj = 0;
    int cnt = 0;
    rep(i,n) {
        minj = i;
        for(int j=i; j < n; j++) {
            if(A[j]<A[minj]) {
                minj = j;
            }
        }
        if(minj != i) {
            swap(A[i],A[minj]);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi A(n);
    rep(i, n) cin >> A[i];

    int cnt = selectionSort(n, A);
    rep(i, n) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
