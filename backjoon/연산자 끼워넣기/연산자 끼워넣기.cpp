#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[11];
int op[4]; // +, -, *, /
int max_val = -1e9, min_val = 1e9;

void dfs(int idx, int result) {
    if (idx == N) {
        max_val = max(max_val, result);
        min_val = min(min_val, result);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (op[i] > 0) {
            --op[i];
            int next = result;
            if (i == 0) next += A[idx];
            else if (i == 1) next -= A[idx];
            else if (i == 2) next *= A[idx];
            else {
                if (result < 0)
                    next = -(-result / A[idx]);
                else
                    next = result / A[idx];
            }
            dfs(idx + 1, next);
            ++op[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < 4; ++i) cin >> op[i];

    dfs(1, A[0]);
    cout << max_val << '\n' << min_val << '\n';
    return 0;
}
