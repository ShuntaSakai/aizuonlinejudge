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

struct Card{ char suit, value; };

void bubbleSort(int n, struct Card A[]) {
    rep(i,n) {
        for(int j=n-1; j>i; j--) {
            if(A[j].value<A[j-1].value) {
                swap(A[j],A[j-1]);  
            }
        }
    }
}

void selectionSort(int n, struct Card A[]) {
    int minj = 0;
    rep(i,n) {
        minj = i;
        for(int j=i; j < n; j++) {
            if(A[j].value<A[minj].value) {
                minj = j;
            }
        }
        if(minj != i) {
            swap(A[i],A[minj]);
        }
    }
}

bool isStable(struct Card A1[], struct Card A2[], int n) {
    rep(i, n) {
        if (A2[i].suit != A1[i].suit) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Card A1[100], A2[100];
    rep(i, n) cin >> A1[i].suit >> A1[i].value;
    rep(i, n) A2[i] = A1[i];

    bubbleSort(n, A1);
    rep(i, n) {
        if(i) cout << " ";
        cout << A1[i].suit << A1[i].value;
    }
    cout << endl;
    cout << "Stable" << endl;

    selectionSort(n, A2);
    rep(i, n) {
        if(i) cout << " ";
        cout << A2[i].suit << A2[i].value;
    }
    cout << endl;
    if(isStable(A1, A2, n)){
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    return 0;
}
