#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000
#define SENTINEL 1000000001

int n;
vi A, B;

void CountingSort(vi &A, vi &B, int k) {
    int n = A.size();
    vi C(k + 1, 0);
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }
    // O(n)
    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }
    // O(k)
    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }
    // O(n)
    for (int i = n-1; i >= 0; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
}

int main() {
    scanf("%d", &n);
    A.resize(n);
    B.resize(n);
    rep(i, n) {
        scanf("%d", &A[i]);
    }
    // O(n + k)
    CountingSort(A, B, 1000000);

    rep(i, n) {
        if (i) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}
