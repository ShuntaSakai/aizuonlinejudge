#include <bits/stdc++.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

int n, A[50];
bool dfs(int i, int m) {
    if (m==0) return true;
    if (i>=n) return false;
    bool res = dfs(i+1, m) || dfs(i+1, m-A[i]);
    return res;
}

bool solve(int m) {
    return dfs(0, m);
}

int main() {
    int q, M;
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &q);
    rep(i, q) {
        scanf("%d", &M);
        if (solve(M)) printf("%s\n", "yes");
        else printf("%s\n", "no");
    }
    
    return 0;
}
