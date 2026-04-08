#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <utility>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

int bubbleSort(int n, vi &A) {
    int flag = 1;
    int cnt = 0;
    while(flag) {
        flag = 0;
        for(int j=n-1; j>0; j--) {
            if(A[j]<A[j-1]) {
                swap(A[j], A[j-1]);
                cnt++;
                flag = 1;
            }
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

    int cnt = bubbleSort(n, A);
    rep(i, n) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
