#include <bits/stdc++.h>
using namespace std;
/*
    1. 물 먼저 bfs
    2. 토끼 bfs
*/
const int INF = 0x3f3f3f3f;//끝 상수
const int SIZE = 102;
vector<string> board;//보드

int dx[]{0,0,1,-1};
int dy[]{1,-1,0,0};
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin >> n >> m;
    board.resize(n);
    
    for(auto &row: board)cin >> row;

    queue<pair<int,int>> b_q, w_q;//토끼, 물;

    int b_visited[SIZE][SIZE], c_visited[SIZE][SIZE];
    memset(b_visited, 0x3f, sizeof b_visited);
    memset(c_visited, 0x3f, sizeof c_visited);

    int e_x,e_y;
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if(board[i][j] == 'B'){//토끼
                b_visited[i][j] = 0;
                b_q.push({i,j});
            }
            else if(board[i][j] == '*'){//물
                c_visited[i][j] = 0;
                w_q.push({i,j});
            }
            else if(board[i][j] == 'C'){
                e_x = i,e_y = j;
            }
        }
    }

    while(!w_q.empty()){//물 먼저 bfs
        auto [x,y] = w_q.front();w_q.pop();
        for(int i{};i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if(c_visited[nx][ny] != INF)continue;
            c_visited[nx][ny] = c_visited[x][y] + 1;
            w_q.push({nx,ny});
        }
    }

    while(!b_q.empty()){
        auto [x,y] = b_q.front(); b_q.pop();
        for(int i{};i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            
            int mark = b_visited[x][y] +  1;
            if(mark >= c_visited[nx][ny] || b_visited[nx][ny] != INF)continue;
            //내가 가려는 곳에 물이 이미 도착했음
            b_visited[nx][ny] = mark;
            b_q.push({nx,ny});
        }
    }
    if(b_visited[e_x][e_y] == INF){
        cout << "Umchichi..Umchichi..";
    }else{
        cout << b_visited[e_x][e_y];
    }
    return 0;
}
