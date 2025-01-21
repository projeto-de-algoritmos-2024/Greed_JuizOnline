#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> blocks(N);
    for (int i = 0; i < N; i++)
        cin >> blocks[i];

    vector<int> dp(M + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = blocks[i]; j <= M; j++) {
            if (dp[j - blocks[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - blocks[i]] + 1);
            }
        }
    }

    cout << dp[M] << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
