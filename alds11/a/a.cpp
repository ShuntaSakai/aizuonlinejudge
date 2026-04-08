#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi A(n);
    rep(i, n) cin >> A[i];
    rep(i, n) {
        if(i) cout << " ";
        cout << A[i];
    } 
    cout << endl;

    for(int i=1; i<n; i++){
        ll v = A[i];
        ll j = i-1;

        while (j>=0 && A[j]>v) {
            A[j+1] = A[j];
            A[j] = v;
            j--;
        }
        rep(i, n) {
        if(i) cout << " ";
            cout << A[i];
        }
        cout << endl;
    }

    return 0;
}
