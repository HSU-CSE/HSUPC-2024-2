#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> graph(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> graph[i].first >> graph[i].second;
    }

    int visited[32] = {};

    int now = k;
    int remain = n;
    while (remain != 1) {
        int next;
        if (visited[now] == 0) {
            next = graph[now].first;
        } else {  // now 아이가 2번 지목됐음
            remain--;
            next = graph[now].second;
        }
        visited[now]++;  // 현재 now라는 아이가 몇 번 지목 됐었는지 체크
        now = next;
    }

    int result;
    for (int i = 1; i <= n; i++) {
        if (visited[i] != 2) {
            result = i;
            break;
        }
    }
    cout << result;
    return 0;
}