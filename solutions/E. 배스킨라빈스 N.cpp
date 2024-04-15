#include <iostream>

using namespace std;
bool solve1(int n) {
    bool dp[197] = {};
    dp[1] = 1;
    for (int i = 5; i <= n; i++) {
        dp[i] = !dp[i - 1];
        if (dp[i - 2]) dp[i] = 0;
        if (dp[i - 3]) dp[i] = 0;
    }
    return !dp[n];
}
bool solve2(int n) { return n % 4 != 1; }
int main() {
    int n;
    cin >> n;
    string result;
    if (solve2(n))
        result = "WIN";
    else
        result = "LOSE";
    cout << result;
    return 0;
}