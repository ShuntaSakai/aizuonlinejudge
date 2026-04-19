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
vi A;

int partition(vi &A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int main() {
    scanf("%d", &n);
    A.resize(n);
    rep(i, n) {
        scanf("%d", &A[i]);
    }

    int x = partition(A, 0, n-1);

    rep(i, n) {
        if (i) printf(" ");
        if (i == x) printf("[%d]", A[i]);
        else printf("%d", A[i]);
    }
    printf("\n");

    return 0;
}
