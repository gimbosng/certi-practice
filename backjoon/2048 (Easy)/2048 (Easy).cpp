#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer = 0;
vector<vector<int>> board;

void move(vector<vector<int>>& b, int dir) {
    for (int i = 0; i < N; ++i) {
        vector<int> line;
        for (int j = 0; j < N; ++j) {
            int val;
            switch (dir) {
            case 0: val = b[i][j]; break;         // left
            case 1: val = b[j][i]; break;         // up
            case 2: val = b[i][N - 1 - j]; break; // right
            case 3: val = b[N - 1 - j][i]; break; // down
            }
            if (val != 0) line.push_back(val);
        }

        vector<int> merged;
        for (int j = 0; j < line.size(); ++j) {
            if (j + 1 < line.size() && line[j] == line[j + 1]) {
                merged.push_back(line[j] * 2);
                ++j;
            }
            else {
                merged.push_back(line[j]);
            }
        }
        while (merged.size() < N) merged.push_back(0);

        for (int j = 0; j < N; ++j) {
            switch (dir) {
            case 0: b[i][j] = merged[j]; break;
            case 1: b[j][i] = merged[j]; break;
            case 2: b[i][N - 1 - j] = merged[j]; break;
            case 3: b[N - 1 - j][i] = merged[j]; break;
            }
        }
    }
}

void dfs(vector<vector<int>> b, int depth) {
    if (depth == 5) {
        for (auto& row : b)
            for (int val : row)
                answer = max(answer, val);
        return;
    }

    for (int dir = 0; dir < 4; ++dir) {
        vector<vector<int>> next = b;
        move(next, dir);
        dfs(next, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    board.resize(N, vector<int>(N));
    for (auto& row : board)
        for (int& val : row)
            cin >> val;

    dfs(board, 0);
    cout << answer << '\n';
    return 0;
}
