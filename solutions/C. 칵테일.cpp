#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    vector<int> v(N);
    for (int &a : v) {
        cin >> a;
    }

    for (int i = 0; i < (1 << N); i++) {
        int sum = 0;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                sum += v[j];
                cnt++;
            }
        }

        int avg = floor((double)sum / cnt + 0.5);
        if (avg == K) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
