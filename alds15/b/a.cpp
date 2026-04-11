#include <bits/stdc++.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define MAX 100000

struct Point {
    double x, y;
};

void kochCurve(int d, Point p1, Point p2) {
    if(d == 0) {
        return;
    }

    Point s, t, u;
    double angle = M_PI * 60.0 / 180.0;

    s.x = (2*p1.x + p2.x) / 3;
    s.y = (2*p1.y + p2.y) / 3;
    t.x = (p1.x + 2*p2.x) / 3;
    t.y = (p1.y + 2*p2.y) / 3;
    u.x = (t.x - s.x) * cos(angle) - (t.y - s.y) * sin(angle) + s.x;
    u.y = (t.x - s.x) * sin(angle) + (t.y - s.y) * cos(angle) + s.y;

    kochCurve(d-1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);
    kochCurve(d-1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    kochCurve(d-1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    kochCurve(d-1, t, p2);
}

int main() {
    Point p1, p2;
    int n;

    scanf("%d", &n);

    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;

    printf("%.8f %.8f\n", p1.x, p1.y);
    kochCurve(n, p1, p2);
    printf("%.8f %.8f\n", p2.x, p2.y);

    return 0;
}
