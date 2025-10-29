#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long B, C;
    cin >> B >> C;

    long long total_supervisors = 0;

    for (int i = 0; i < N; ++i) {
        // 총감독관 1명은 반드시 필요
        total_supervisors += 1;
        A[i] -= B;

        if (A[i] > 0) {
            // 필요한 부감독관 수 계산
            total_supervisors += (A[i] + C - 1) / C;
        }
    }

    cout << total_supervisors << '\n';
    return 0;
}
