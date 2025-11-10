#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int board[8][8], temp[8][8];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int answer = 0;

void copy_board() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            temp[i][j] = board[i][j];
}

void spread_virus() {
    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (temp[i][j] == 2)
                q.push({ i, j });

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (temp[nx][ny] == 0) {
                temp[nx][ny] = 2;
                q.push({ nx, ny });
            }
        }
    }
}

int count_safe() {
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (temp[i][j] == 0)
                ++cnt;
    return cnt;
}

void make_wall(int count) {
    if (count == 3) {
        copy_board();
        spread_virus();
        answer = max(answer, count_safe());
        return;
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] == 0) {
                board[i][j] = 1;
                make_wall(count + 1);
                board[i][j] = 0;
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    make_wall(0);
    cout << answer << '\n';
    return 0;
}
