#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 한 번에 1칸 또는 2칸 오를 때 최소 비용을 구한다.
int solve(int index, const vector<int>& cost, vector<int>& memo) {
    if (index >= (int)cost.size()) return 0;
    if (memo[index] != -1) return memo[index];

    int oneStep = solve(index + 1, cost, memo);
    int twoSteps = solve(index + 2, cost, memo);
    return memo[index] = cost[index] + min(oneStep, twoSteps);
}

int minCostClimbingStairs(const vector<int>& cost) {
    vector<int> memo(cost.size(), -1);
    return min(solve(0, cost, memo), solve(1, cost, memo));
}

int main() {
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << '\n';
}
