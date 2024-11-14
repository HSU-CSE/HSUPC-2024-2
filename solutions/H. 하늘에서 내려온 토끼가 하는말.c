#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INF 0x3f3f3f3f
#define SIZE 102

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char board[SIZE][SIZE];
int b_visited[SIZE][SIZE], c_visited[SIZE][SIZE];

typedef struct {
    int x, y;
} QueueNode;

typedef struct {
    QueueNode data[SIZE * SIZE];
    int front, back;
} Queue;

void initQueue(Queue *q) {
    q->front = q->back = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->back;
}

void enqueue(Queue *q, int x, int y) {
    q->data[q->back++] = (QueueNode){x, y};
}

QueueNode dequeue(Queue *q) {
    return q->data[q->front++];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Queue b_q, w_q;
    initQueue(&b_q);
    initQueue(&w_q);

    memset(b_visited, INF, sizeof(b_visited));
    memset(c_visited, INF, sizeof(c_visited));

    int e_x, e_y;
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'B') { // 토끼
                b_visited[i][j] = 0;
                enqueue(&b_q, i, j);
            } else if (board[i][j] == '*') { // 물
                c_visited[i][j] = 0;
                enqueue(&w_q, i, j);
            } else if (board[i][j] == 'C') {
                e_x = i;
                e_y = j;
            }
        }
    }

    // 물의 BFS
    while (!isEmpty(&w_q)) {
        QueueNode node = dequeue(&w_q);
        int x = node.x, y = node.y;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (c_visited[nx][ny] != INF) continue;
            c_visited[nx][ny] = c_visited[x][y] + 1;
            enqueue(&w_q, nx, ny);
        }
    }

    // 토끼의 BFS
    while (!isEmpty(&b_q)) {
        QueueNode node = dequeue(&b_q);
        int x = node.x, y = node.y;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            int mark = b_visited[x][y] + 1;
            if (mark >= c_visited[nx][ny] || b_visited[nx][ny] != INF) continue;
            b_visited[nx][ny] = mark;
            enqueue(&b_q, nx, ny);
        }
    }

    if (b_visited[e_x][e_y] == INF) {
        printf("Umchichi..Umchichi..\n");
    } else {
        printf("%d\n", b_visited[e_x][e_y]);
    }

    return 0;
}
