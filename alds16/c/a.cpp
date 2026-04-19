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

struct Card {
    char mark;
    int value;
};

vector<Card> A, B;

void merge(vector<Card> &A, int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    vector<Card> L(n1+1), R(n2+1);
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1].value = R[n2].value = SENTINEL;

    int i = 0, j = 0;
    for (int k=left; k<right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(vector<Card> &A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(vector<Card> &B, int p, int r) {
    int x = B[r].value;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (B[j].value <= x) {
            i++;
            swap(B[i], B[j]);
        }
    }
    swap(B[i + 1], B[r]);
    return i + 1;
}

void quickSort(vector<Card> &B, int p, int r) {
    if (p < r) {
        int q = partition(B, p, r);
        quickSort(B, p, q - 1);
        quickSort(B, q + 1, r);
    }
}

int main() {
    bool stable = true;

    scanf("%d", &n);
    B.resize(n);
    rep(i, n) {
        scanf(" %c %d", &B[i].mark, &B[i].value);
    }

    A = B;

    mergeSort(A, 0, n);
    quickSort(B, 0, n-1);

    rep(i, n) {
        if(A[i].mark != B[i].mark) {
            stable = false;
            break;
        }
    }
    
    if (stable) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    rep(i, n) {
        printf("%c %d", B[i].mark, B[i].value);
        printf("\n");
    }

    return 0;
}
