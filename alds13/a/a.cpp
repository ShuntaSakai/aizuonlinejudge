#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <sstream>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

int top, S[1000];

void initialize() {
    top = 0;
}

void push(int x) {
    S[++top]=x;
}

int pop() {
    return S[top--];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initialize();

    string line;
    getline(cin, line);

    stringstream ss(line);
    string x;
    while (ss >> x) {
        if( x=="+" || x=="-" || x=="*") {
            int b=pop();
            int a=pop();

            if(x=="+") {
                push(a+b);
            } else if(x=="-") {
                push(a-b);
            } else if(x=="*") {
                push(a*b);
            }
        } else {
            push(stoi(x));
        }
    }

    cout << pop() << endl;

    return 0;
}
