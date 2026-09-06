#include <iostream>
#include <vector>
using namespace std;

long long fibonacci(int n) {
    if (n <= 1) return n;

    vector<long long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    cout << fibonacci(10) << '\n';
}
