#include <bits/stdc++.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

int A[MAX];
int n;

int binarySearch(int key) {
    int left = 0, right = n;
    while(left < right) {
        int mid = (left + right) / 2;
        if (A[mid] == key) return mid;
        if (A[mid] < key) left = mid + 1;
        else right = mid;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &A[i]);
    }

    int q, T[MAX];
    scanf("%d", &q);
    rep(i, q) {
        scanf("%d", &T[i]);
    }

    int ans = 0;
    rep(j, q) {
        if (binarySearch(T[j]) != -1) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
