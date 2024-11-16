#include <stdio.h>

int N;
char selected[10]; // 최대 10개의 과일 선택 가능
char fruits[] = {'C', 'K', 'M', 'S', 'W'};
int fruit_count = 5;

// 과일 선택하기
void dfs(int i) {
    // N개의 과일을 고른 순간 출력
    if (i == N) {
        for (int j = 0; j < N; ++j) {
            printf("%c", selected[j]);
            if (j < N - 1) printf(" "); // 마지막 과일 뒤에는 공백 제외
        }
        printf("\n");
        return;
    }

    // 재귀적으로 과일 선택
    for (int k = 0; k < fruit_count; ++k) {
        if (i == 0 || selected[i - 1] != fruits[k]) { // 이전에 고른 과일은 선택할 수 없음
            selected[i] = fruits[k];
            dfs(i + 1);
        }
    }
}

int main() {
    scanf("%d", &N); // N 입력
    dfs(0); // DFS 시작
    return 0;
}
