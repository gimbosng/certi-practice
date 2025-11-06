#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[16], P[16], dp[16];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> T[i] >> P[i];

    for (int i = N - 1; i >= 0; --i) {
        int next_day = i + T[i];
        if (next_day <= N)
            dp[i] = max(P[i] + dp[next_day], dp[i + 1]);
        else
            dp[i] = dp[i + 1];
    }

    cout << dp[0] << '\n';
    return 0;
}
