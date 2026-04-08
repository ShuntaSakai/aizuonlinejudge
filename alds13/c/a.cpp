#include <bits/stdc++.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

int top, Q[MAX];
int head, tail;

struct Node{ int key; Node *prev, *next; };

Node *nil;

void init() {
    nil = (Node *)malloc(sizeof(Node));
    nil->prev = nil->next = nil;
}

void insert(int key) {
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

Node* listSearch(int key) {
    Node *cur = nil->next; // 番兵の次（先頭要素）から探索を開始
    while (cur != nil) { // 番兵に達するまで探索を続ける（すなわち末尾の要素まで探索を行う）
        if (cur->key == key) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

void deleteNode(Node *x) {
    if (x == nullptr || x == nil) return; // 見つからない場合や番兵は削除しない
    x->prev->next = x->next;
    x->next->prev = x->prev;
    free(x);
}

void deleteKey(int key) {
    deleteNode(listSearch(key));
}

void deleteFirst() {
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int n;
    char command[20];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(command, "delete") == 0) {
            int x;
            scanf("%d", &x);
            deleteKey(x);
        } else if (strcmp(command, "deleteFirst") == 0) {
            deleteFirst();
        } else if (strcmp(command, "deleteLast") == 0) {
            deleteLast();
        }
    }

    int isf = 0;
    while (nil->next != nil) {
        if (isf++ > 0) {
            printf(" ");
        }
        printf("%d", nil->next->key);
        deleteFirst();
    }
    printf("\n");

    return 0;
}
