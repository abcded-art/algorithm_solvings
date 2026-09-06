#include <iostream>
#include <vector>
using namespace std;

// 장애물이 없는 h x w 격자에서 오른쪽/아래로만 이동하는 경로 수.
long long countPaths(int h, int w) {
    if (h <= 0 || w <= 0) return 0;

    vector<vector<long long>> dp(h, vector<long long>(w, 0));
    dp[0][0] = 1;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y > 0) dp[y][x] += dp[y - 1][x];
            if (x > 0) dp[y][x] += dp[y][x - 1];
        }
    }
    return dp[h - 1][w - 1];
}

int main() {
    cout << countPaths(3, 4) << '\n'; // 10
}
