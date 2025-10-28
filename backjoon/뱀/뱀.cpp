#include <iostream>
#include <deque>
#include <vector>
#include <map>
using namespace std;

int N, K, L;
vector<vector<int>> board;
map<int, char> direction_changes;

// 방향: 오른쪽(0), 아래(1), 왼쪽(2), 위(3)
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int simulate() {
    deque<pair<int, int>> snake;
    snake.push_back({ 0, 0 });
    board[0][0] = 2; // 뱀의 위치 표시

    int time = 0, dir = 0;

    while (true) {
        time++;
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        // 벽이나 자기 몸에 부딪히면 종료
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] == 2)
            break;

        // 사과가 있으면 머리만 이동
        if (board[nx][ny] == 1) {
            board[nx][ny] = 2;
            snake.push_front({ nx, ny });
        }
        else { // 사과 없으면 머리 이동 + 꼬리 제거
            board[nx][ny] = 2;
            snake.push_front({ nx, ny });
            auto tail = snake.back();
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }

        // 방향 전환
        if (direction_changes.count(time)) {
            char c = direction_changes[time];
            if (c == 'L') dir = (dir + 3) % 4;
            else if (c == 'D') dir = (dir + 1) % 4;
        }
    }

    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    board.assign(N, vector<int>(N, 0));

    cin >> K;
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1; // 사과 위치
    }

    cin >> L;
    for (int i = 0; i < L; ++i) {
        int t;
        char c;
        cin >> t >> c;
        direction_changes[t] = c;
    }

    cout << simulate() << '\n';
    return 0;
}