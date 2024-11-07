#include <bits/stdc++.h>
using namespace std;

int N;

void solve() {
    int n = 1;
    int m = 1;

    while(n * m < N) {
        if (n > m) m++;
        else n++;
    }

    cout << n + m;
}

void input() {
    cin >> N;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    input();
    solve();
    return 0;
}
