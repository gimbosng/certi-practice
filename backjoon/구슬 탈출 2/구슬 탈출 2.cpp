#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

const int MAX = 10;
char board[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];
int N, M;

// 상, 하, 좌, 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 구슬 이동 함수
pair<pair<int, int>, int> move(int x, int y, int dir) {
    int cnt = 0;
    while (true) {
        if (board[x + dx[dir]][y + dy[dir]] == '#' || board[x][y] == 'O') break;
        x += dx[dir];
        y += dy[dir];
        cnt++;
    }
    return make_pair(make_pair(x, y), cnt);
}

int bfs(int rx, int ry, int bx, int by) {
    queue<tuple<int, int, int, int, int>> q;
    q.push(make_tuple(rx, ry, bx, by, 0));
    visited[rx][ry][bx][by] = true;

    while (!q.empty()) {
        int crx, cry, cbx, cby, depth;
        tie(crx, cry, cbx, cby, depth) = q.front(); q.pop();
        if (depth >= 10) return -1;

        for (int dir = 0; dir < 4; ++dir) {
            auto red = move(crx, cry, dir);
            auto blue = move(cbx, cby, dir);
            int nrx = red.first.first, nry = red.first.second, rcnt = red.second;
            int nbx = blue.first.first, nby = blue.first.second, bcnt = blue.second;

            if (board[nbx][nby] == 'O') continue;
            if (board[nrx][nry] == 'O') return depth + 1;

            if (nrx == nbx && nry == nby) {
                if (rcnt > bcnt) {
                    nrx -= dx[dir];
                    nry -= dy[dir];
                }
                else {
                    nbx -= dx[dir];
                    nby -= dy[dir];
                }
            }

            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push(make_tuple(nrx, nry, nbx, nby, depth + 1));
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int rx, ry, bx, by;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                rx = i; ry = j;
            }
            else if (board[i][j] == 'B') {
                bx = i; by = j;
            }
        }
    }

    cout << bfs(rx, ry, bx, by) << '\n';
    return 0;
}
