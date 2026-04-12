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

int n, ans;
vi A;

void merge(vi &A, int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    vi L(n1+1), R(n2+1);
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;

    int i = 0, j = 0;
    for (int k=left; k<right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
            ans++;
        } else {
            A[k] = R[j++];
            ans++;
        }
    }
}

void mergeSort(vi &A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    scanf("%d", &n);
    A.resize(n);
    rep(i, n) {
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n);

    rep(i, n) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", ans);

    return 0;
}
