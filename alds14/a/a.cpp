#include <bits/stdc++.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, S[MAX];
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &S[i]);
    }

    int q, T[MAX];
    scanf("%d", &q);
    rep(i, q) {
        scanf("%d", &T[i]);
    }

    int ans = 0;
    rep(j, q) {
        rep(i, n) {
            if (S[i] == T[j]) {
                ans++;
                break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
