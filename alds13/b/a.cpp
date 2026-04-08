#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <sys/wait.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

int top, Q[MAX];
int head, tail;

struct Process{ string name; int time; };

void initialize() {
    head = tail = 0;
}

bool isEmpty() {
    return head == tail;
}

bool isFull() {
    return head == (tail+1) % MAX;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Error: Queue is Full" << endl;
    }

    Q[tail] = x;

    if(tail+1 == MAX) {
        tail = 0;
    } else {
        tail++;
    }
}

int dequeue() {
    if (isEmpty()) {
        cout << "Error: Queue is Empty" << endl;
    }

    int x = Q[head];

    if(head+1 == MAX) {
        head = 0;
    } else {
        head++;
    }

    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initialize();

    int n, t;
    cin >> n >> t;

    Process P[MAX];
    rep(i, n) {
        cin >> P[i].name >> P[i].time;
        enqueue(i);
    }

    int now = 0;
    while (!isEmpty()) {
        int idx = dequeue();

        if(P[idx].time <= t) {
            now += P[idx].time;
            cout << P[idx].name << " " << now << endl;
        } else {
            P[idx].time -= t;
            now += t;
            enqueue(idx);
        }
    }

    return 0;
}
