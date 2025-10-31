#include <iostream>
using namespace std;

int N, M, x, y, K;
int map[20][20];
int dice[6]; // 0: top, 1: bottom, 2: left, 3: right, 4: front, 5: back
int dx[4] = { 0, 0, -1, 1 }; // 동, 서, 북, 남
int dy[4] = { 1, -1, 0, 0 };

void roll(int dir) {
    int temp[6];
    for (int i = 0; i < 6; ++i) temp[i] = dice[i];

    if (dir == 0) { // 동
        dice[0] = temp[2];
        dice[1] = temp[3];
        dice[2] = temp[1];
        dice[3] = temp[0];
    }
    else if (dir == 1) { // 서
        dice[0] = temp[3];
        dice[1] = temp[2];
        dice[2] = temp[0];
        dice[3] = temp[1];
    }
    else if (dir == 2) { // 북
        dice[0] = temp[4];
        dice[1] = temp[5];
        dice[4] = temp[1];
        dice[5] = temp[0];
    }
    else if (dir == 3) { // 남
        dice[0] = temp[5];
        dice[1] = temp[4];
        dice[4] = temp[0];
        dice[5] = temp[1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];

    for (int i = 0; i < K; ++i) {
        int cmd;
        cin >> cmd;
        int dir = cmd - 1;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

        roll(dir);
        x = nx;
        y = ny;

        if (map[x][y] == 0) {
            map[x][y] = dice[1]; // 바닥면
        }
        else {
            dice[1] = map[x][y];
            map[x][y] = 0;
        }

        cout << dice[0] << '\n'; // 윗면 출력
    }

    return 0;
}
