#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {5, 2, 9, 1, 3};

    sort(nums.begin(), nums.end());
    for (int x : nums) cout << x << ' ';
    cout << '\n';

    sort(nums.begin(), nums.end(), greater<int>());
    for (int x : nums) cout << x << ' ';
    cout << '\n';

    vector<pair<int, int>> pairs = {{2, 3}, {1, 9}, {2, 1}};

    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    for (auto [a, b] : pairs) {
        cout << a << ',' << b << '\n';
    }
}
