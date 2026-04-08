#include <bits/stdc++.h>
#include <iostream>
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
void maxHeapify(int A[], int i, int H) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= H && A[l] > A[largest]) largest = l;
    if (r <= H && A[r] > A[largest]) largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest, H);
    } 
}

void buildMaxHeap(int A[], int H) {
    int i;
    for (i=H/2; i>0; i--) {
        maxHeapify(A, i, H);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H;
    cin >> H;
    vi A(H+1);
    rep(i, H) cin >> A[i+1];

    buildMaxHeap(A.data(), H);    

    rep(i, H) {
        cout << " " << A[i+1];
    }
    return 0;
}
