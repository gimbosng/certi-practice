#include <iostream>
using namespace std;

int N, M, r, c, d;
int room[50][50];
bool cleaned[50][50];
int dx[4] = { -1, 0, 1, 0 }; // 북 동 남 서
int dy[4] = { 0, 1, 0, -1 };
int answer = 0;

bool inRange(int x, int y) {
    return x >= 0 && y >= 0 && x < N&& y < M;
}

void simulate() {
    while (true) {
        if (!cleaned[r][c]) {
            cleaned[r][c] = true;
            ++answer;
        }

        bool found = false;
        for (int i = 0; i < 4; ++i) {
            d = (d + 3) % 4; // 반시계 회전
            int nx = r + dx[d], ny = c + dy[d];
            if (inRange(nx, ny) && room[nx][ny] == 0 && !cleaned[nx][ny]) {
                r = nx; c = ny;
                found = true;
                break;
            }
        }

        if (found) continue;

        // 후진
        int back = (d + 2) % 4;
        int bx = r + dx[back], by = c + dy[back];
        if (inRange(bx, by) && room[bx][by] == 0) {
            r = bx; c = by;
        }
        else {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> r >> c >> d;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> room[i][j];

    simulate();
    cout << answer << '\n';
    return 0;
}
