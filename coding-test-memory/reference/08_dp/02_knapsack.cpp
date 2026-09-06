#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 0/1 Knapsack
    // 각 물건은 최대 한 번만 사용한다.
    vector<int> weight = {3, 4, 5};
    vector<int> value = {30, 50, 60};
    int capacity = 8;

    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < (int)weight.size(); i++) {
        // 뒤에서 앞으로 순회해야 같은 물건을 여러 번 쓰지 않는다.
        for (int w = capacity; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    cout << dp[capacity] << '\n';
}
