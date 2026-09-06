#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxWindowSum(const vector<int>& nums, int k) {
    // 길이가 k인 연속 구간만 다룬다.
    if (k <= 0 || k > (int)nums.size()) return 0;

    long long windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    long long answer = windowSum;

    for (int right = k; right < (int)nums.size(); right++) {
        windowSum += nums[right];
        windowSum -= nums[right - k];
        answer = max(answer, windowSum);
    }

    return answer;
}

int main() {
    vector<int> nums = {1, 3, 2, 6, 4, 5};
    cout << maxWindowSum(nums, 3) << '\n';
}
