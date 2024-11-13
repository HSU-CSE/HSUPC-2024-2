#include <bits/stdc++.h>
using namespace std;
/*
    1. 물 먼저 bfs
    2. 토끼 bfs
*/

const int INF = 0x3f3f3f3f;
vector<string> board; // 보드
int n, m;

int dist(pair<int, int> &e_point, pair<int, int> tmp)
{
    return abs(e_point.first - tmp.first) + abs(e_point.second - tmp.second);
}
int get_dist(pair<int, int> &e_point, char target)
{
    int ret{INF};
    for (int i{}; i < n; i++)
    {
        for (int j{}; j < m; j++)
        {
            if (board[i][j] == target)
            {
                ret = min(ret, dist(e_point, {i, j}));
            }
        }
    }

    return ret;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    board.resize(n);

    for (auto &row : board)
        cin >> row;

    pair<int, int> e_point;

    for (int i{}; i < n; i++)
    {
        for (int j{}; j < m; j++)
        {
            if (board[i][j] == 'C')
            {
                e_point = {i, j};
            }
        }
    }

    int water_dist = get_dist(e_point, '*');
    int bunny_dist = get_dist(e_point, 'B');
    if(bunny_dist < water_dist)cout << bunny_dist;
    else cout << "Umchichi..Umchichi..";

    return 0;
}
