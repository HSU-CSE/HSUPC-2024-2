#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<char> selected;
char fruits[] = {'C', 'K', 'M', 'S', 'W'};

// 과일 선택하기
void dfs(int i) {
    // N개의 과일을 고른 순간 출력
    if (i == N) {
        for (int j = 0; j < N; ++j) {
            cout << selected[j];
            if (j < N - 1) cout << " "; // 마지막 과일 뒤에는 공백 제외
        }
        cout << endl;
        return;
    }

    // 아직 N개의 과일을 다 고르지 못했다면 재귀적으로 선택
    for (char currFruit : fruits) {
        if (i == 0 || selected[i - 1] != currFruit) { // 이전에 고른 과일은 선택할 수 없음
            selected[i] = currFruit;
            dfs(i + 1);
        }
    }
}

int main() {
    cin >> N;
    selected.resize(N);
    dfs(0);
    return 0;
}
