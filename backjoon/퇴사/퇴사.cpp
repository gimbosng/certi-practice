#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int board[500][500];
bool visited[500][500];
int answer = 0;

// 상하좌우 방향
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        answer = max(answer, sum);
        return;
    }

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + board[nx][ny]);
        visited[nx][ny] = false;
    }
}

// DFS로 만들 수 없는 'ㅗ' 모양 처리
void check_t_shape(int x, int y) {
    int center = board[x][y];
    for (int i = 0; i < 4; ++i) {
        int temp = center;
        bool valid = true;
        for (int j = 0; j < 3; ++j) {
            int dir = (i + j) % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                valid = false;
                break;
            }
            temp += board[nx][ny];
        }
        if (valid) answer = max(answer, temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;
            check_t_shape(i, j);
        }
    }

    cout << answer << '\n';
    return 0;
}