#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, S[20][20], answer = 1e9;
bool selected[20];

void dfs(int idx, int count) {
    if (count == N / 2) {
        vector<int> start, link;
        for (int i = 0; i < N; ++i) {
            if (selected[i]) start.push_back(i);
            else link.push_back(i);
        }

        int start_sum = 0, link_sum = 0;
        for (int i = 0; i < N / 2; ++i)
            for (int j = 0; j < N / 2; ++j) {
                start_sum += S[start[i]][start[j]];
                link_sum += S[link[i]][link[j]];
            }

        answer = min(answer, abs(start_sum - link_sum));
        return;
    }

    for (int i = idx; i < N; ++i) {
        if (!selected[i]) {
            selected[i] = true;
            dfs(i + 1, count + 1);
            selected[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> S[i][j];

    dfs(0, 0);
    cout << answer << '\n';
    return 0;
}
