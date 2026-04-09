#include <bits/stdc++.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define M 1046527 // 大きめの素数を選ぶことで、衝突を減らす
#define L 14

int n;
char D[M][L];

// 文字列を数値に変換する関数
int getChar(char ch) {
    if (ch == 'A') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else if (ch == 'T') return 4;
    else return 0;
}

// 文字列を5進数表現として解釈して10進数の整数に変換する関数（符号化）
long long getKey(char str[]) {
    long long key = 0, p = 1;
    for (int i = 0; i < strlen(str); i++) {
        key += getChar(str[i]) * p;
        p *= 5; // 5進数で表現するため、基数は5
    }
    return key;
}

// ハッシュ関数
int h1(long long key) {
    return key % M;
}
int h2(long long key) {
    return 1 + (key % (M-1));
}

bool find(char str[]) {
    long long key = getKey(str), i = 0, h;
    while(true) {
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(D[h], str) == 0) return true;
        else if (strlen(D[h]) == 0) return false;
        i++;
    }
    return false;
}

bool insert(char str[]) {
    long long key = getKey(str), i = 0, h;
    while(true) {
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(D[h], str) == 0) return true;
        else if (strlen(D[h]) == 0) {
            strcpy(D[h], str);
            return false;
        }
        i++;
    }
    return false;
}

int main() {
    char command[10], word[L];

    for(int i=0; i<M; i++) {
        D[i][0] = '\0'; // ハッシュテーブルの初期化
    }

    scanf("%d", &n);
    rep(i, n) {
        scanf("%s %s", command, word);

        if (command[0] == 'i') {
            insert(word);
        } else {
            if (find(word)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}
