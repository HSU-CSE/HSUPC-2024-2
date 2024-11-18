#include <bits/stdc++.h>
using namespace std;

int K, N;
vector<int> v;
bool answer = false;

void recursive(int depth, int sum, int cnt) {
    if (depth == N) {
        int avg = floor((double)sum / cnt + 0.5);
        if (avg == K) {
            answer = true;
        }
        return;
    }

    recursive(depth + 1, sum, cnt);
    recursive(depth + 1, sum + v[depth], cnt + 1);
}

int main() {
    cin >> K >> N;

    v.resize(N);
    for (int &a : v) {
        cin >> a;
    }

    recursive(0, 0, 0);

    cout << (answer ? "YES" : "NO");

    return 0;
}